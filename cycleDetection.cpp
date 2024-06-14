#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void makeCycle(node* &head,int pos){
    node*   newNode;
    node* current=head;
    int counter=1;
    while(current->next!=NULL){
        if(counter==pos){
            newNode=current;
        }
        current=current->next;
        counter++;
    }
    current->next=newNode;
}
void push(node* &head,int val){
    node* newNode=new node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    node* current=head;

    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
}
bool cycleDetection(node* &head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void display(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
void removeCycle(node* head){
    node* fast=head;
    node* slow=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (fast!=slow);
    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
    
}
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    makeCycle(head,3);
    // display(head);
    // display(head);
    bool i=cycleDetection(head);
    cout<<i<<endl;
    removeCycle(head);
    display(head);
    return 0;
}