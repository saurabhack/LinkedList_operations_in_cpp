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
void display(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
node* reverseK(node* head,int k){
    node* current=head;
    node* prev=NULL;
    node* next;
    int counter=0;
    while(current!=NULL && counter<k){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        counter++;
    }
    if(next!=NULL){
        head->next=reverseK(next,k);
    }
    return prev;
}
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    display(head);
    int k=3;
    node* newHead=reverseK(head,k);
    display(newHead);
    return 0;
}