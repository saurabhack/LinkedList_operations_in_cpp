#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* newNode=new node(val);
    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}
void insertAtEnd(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* newNode=new node(val);
    node* current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
}
void display(node* head){
    node* current=head;
    while(current!=NULL){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAtHead(node* &head){
    node* current=head;
    head=head->next;
    head->prev=NULL;
    delete current;
}
void deleteAtPos(node* &head,int pos){
    node* temp=head;
    int counter=1;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    while(temp!=NULL && counter!=pos){
        temp=temp->next;
        counter++;
    }
    temp->prev->next=temp->next;
    if(temp!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}
int main(){
    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    display(head);
    deleteAtPos(head,2);
    display(head);
    deleteAtPos(head,1);
    display(head);
    insertAtHead(head,2);
    display(head);

return 0;
}