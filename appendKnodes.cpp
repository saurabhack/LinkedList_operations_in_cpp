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
int totalLength(node* head){
    int counter=0;
    node* current=head;
    while(current!=NULL){
        current=current->next;
        counter++;
    }
    return counter;
}
node* appendK(node* head,int k){
    node* newTail;
    node* newHead;
    node* tail=head;
    node* current=head;
    int counter=1;
    while(current->next!=NULL){
        
        if(counter==k-1){
            newTail=current;
        }
        if(counter==k){
            newHead=current;
        }
        current=current->next;
        counter++;
    }
    current->next=tail;
    newTail->next=NULL;
    head=newHead;
    return head;
}
void push(node* &head,int val){
    node* newNode=new node(val);
    if(head==NULL){
        head=newNode;
        return ;
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
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    display(head);
    node* newheader=appendK(head,3);
    display(newheader);
    return 0;
}