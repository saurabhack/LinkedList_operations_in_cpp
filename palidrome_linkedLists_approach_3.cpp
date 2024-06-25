#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
       data=val;
       next=NULL; 
    }
};
void push(node* &head,int data){
    node* newNode=new node(data);
    node* current=head;
    if(head==NULL){
        head=newNode;
        return;
    }
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}
void display(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
node* middle(node* head){
    node* slow=head;
    node* fast=head->next;
        while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* reverse(node* head){
    node* prev=NULL;
    node* current=head;
    while(current!=NULL){
        node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
bool is_palidrome(node* head){
    node* mid=middle(head);
    node* temp=mid->next;
    mid->next=reverse(temp);
    node* head1=head;
    node* head2=mid->next;
    while( head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    display(head);
    cout<<is_palidrome(head)<<endl;
return 0;
}
