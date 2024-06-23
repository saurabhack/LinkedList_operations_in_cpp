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
node* unsortedRemove(node* head){
    node* current=head;
    while(current!=NULL ){
        node* temp=current->next;
        while(temp!=NULL and temp->next!=NULL){
            if(current->data==temp->next->data){
                node* todele=temp->next;
                temp->next=temp->next->next;
                delete todele;
            }else{
                temp=temp->next;
            }
           
        }
         current=current->next;
    }
    return head;
}
node* removeDuplicate(node* head){
    node* current=head;
    if(head==NULL){
        return NULL;
    }
    while(current!=NULL){
        if((current->next!=NULL) and current->data==current->next->data  ){
            node* todele=current->next;
            current->next=current->next->next;
            delete todele;
        }
        else{
            current=current->next;
        }
        
    }
    return head;
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
    // push(head,1);
    // push(head,3);
    // push(head,3);
    // push(head,4);
    // display(head);
    // node* newNode=removeDuplicate(head);
    //  display(newNode);
    push(head,1);
    push(head,2);
    push(head,1);
    push(head,2);
    push(head,2);
    push(head,2);
    push(head,7);
    push(head,7);
    push(head,-1);

    head=unsortedRemove(head);
    display(head);
    return 0;
}