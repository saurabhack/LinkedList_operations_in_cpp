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
void insertAtEnd(node* &head,int val){
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
void insertAtBegining(node* &head,int val){
    node* first=new node(val);
    first->next=head;
    head=first;

}
bool searching(node* head,int key){
    node* current=head;
    while(current!=NULL){
        if(current->data==key){
            return true;
        }
        current=current->next;
    }
    return false;
}
void deleteAtFirst(node* &head){
    node* dele=head;
    head=head->next;
    delete dele;
}
void deletion(node* &head,int val){
    node* current=head;
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtFirst(head);
        return;
    }
    while(current->next->data!=val){
        current=current->next;
    }

    node* dele=current->next;
    current->next=current->next->next;
    delete dele;
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
    node* prev=NULL;
    node* current=head;
    node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
node* reverseRecursive(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* reverse=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return reverse;
}
int main(){
    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtBegining(head,5);
    // deletion(head,2);
    // deleteAtFirst(head);
    display(head);
    node* rev=reverseRecursive(head);
    display(rev);
    // bool ans=searching(head,2);
    // if(!ans){
    //     cout<<"element does not exists"<<endl;
    // }else{
    //     cout<<"element exist"<<endl;
    // }
    return 0;
}