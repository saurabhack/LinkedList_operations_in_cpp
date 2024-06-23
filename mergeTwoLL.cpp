#include<iostream>
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
node* merge(node* head1,node* head2){
    node* p1=head1;
    node* p2=head2;
    node* dummy=new node(-1);
    node* p3=dummy;
    while(p1!=NULL and p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }else if(p2->data<p1->data){
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummy->next;
}
void push(node* &head,int val){
    node* newNode=new node(val);
    node* current=head;
    if(head==NULL){
        head=newNode;
        return ;
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
int main(){
    node* head1=NULL;
    node* head2=NULL;
    push(head1,1);
    push(head1,4);
    push(head1,6);
    push(head1,8);
    push(head2,2);
    push(head2,5);
    push(head2,7);
    display(head1);
    display(head2);
    node* newNode=merge(head1,head2);
    display(newNode);
    return 0;
}