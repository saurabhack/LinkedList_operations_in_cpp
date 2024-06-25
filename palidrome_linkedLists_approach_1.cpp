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

node* reverse(node* head){
    node* current=head;
    node* prev=NULL;
    while(current!=NULL){
        node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
int size_linkedLists(node* head){
    node* current=head;
    int counter=0;
    while(current!=NULL){
        counter++;
        current=current->next;
    }
    return counter;
}

bool is_palidrome(node* head){
    node* reversed=reverse(head);
    node* current2=reversed;
    node* current=head;
    int counter=0;
    while(current2!=NULL and current!=NULL){
        if(current2->data==current->data){
            counter++;
        }
        current=current->next;
        current2=current2->next;
    }
    int size=size_linkedLists(head);
    if(counter==size){
        return true;
    }
    return false;
}

int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,1);
    display(head);
    node* mew=reverse(head);
    display(mew);
    if(is_palidrome(head)==1){
        cout<<"linkedlist is palidrome"<<endl;
    }else{
        cout<<"linkedlist is not palidrome"<<endl;
    }
    return 0;
}