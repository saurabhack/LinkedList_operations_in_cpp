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
void insertAtHead(node* &head,int val){
    node* current=head;
    node* newHead=new node(val);
    if(head==NULL){
        newHead->next=newHead;
        head=newHead;
        return;
    }
    while(current->next!=head){
        current=current->next;
    }
    current->next=newHead;
    newHead->next=head;
    head=newHead;
}
void push(node* &head,int val){
    node* newNode=new node(val);
    node* current=head;
    if(head==NULL){
        insertAtHead(head,val);
        return ;
    }
    while(current->next!=head){
        current=current->next;
    }
    current->next=newNode;
    newNode->next=head;
}
void display(node* head){
 
 
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
}
bool searching(node* head,int key){
node* current=head;
while(current!=head){
    current=current->next;
    if(current->data==key){
        return true;
    }
}
return false;
}
void deleteAtHead(node* &head){
    node* current=head;
    while(current->next!=head){
        current=current->next;
    }
    node* todelete=head;
    current->next=head->next;
    head=head->next;
    delete todelete;
}
void DeleteNode(node* &head,int pos){
    if(pos==0){
        deleteAtHead(head);
        return ;
    }
    int counter=0;
    node* current=head;
    while(counter!=pos-1){
        current=current->next;
        counter++;
    }
    node* todelete=current->next;
    current->next=current->next->next;
    delete todelete;
}
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    display(head);
    DeleteNode(head,2);
    display(head);
    DeleteNode(head,0);
    display(head);
    cout<<searching(head,4)<<endl;
    display(head);
    // cout<<searching(head,1)<<endl;
    // if(!searching(head,1)){
    //     cout<<"element is exists in these linked lists"<<endl;
    // }else{
    //     cout<<"element does not exists in these linked lists"<<endl;
    // }
    return 0;
}
