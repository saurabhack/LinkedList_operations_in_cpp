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
void evenAndOdd(node* head){
    node* odd=head;
    node* even=head->next;
    node* startEven=even;
    while(odd->next!=NULL and even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=startEven;
    if(odd->next!=NULL){
        even->next=NULL;
    }

}
void push(node* &head,int val){
    node* current=head;

    node* newNode=new node(val);
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
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    display(head);
    evenAndOdd(head);
    display(head);
    return 0;
}