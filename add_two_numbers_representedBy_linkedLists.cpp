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
    if(head==NULL){
        head=newNode;
        return;
    }
    node* current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newNode;

}
node* reverse(node* head){
    node* prev=NULL;
    node* current=head;
    while(current!=NULL){
        node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
node* addTwoLL(node* head1,node* head2){
    int first=0;
    int second=0;
    node* current1=head1;
    node* current2=head2;
    while(current1!=NULL or current2!=NULL){
        if(current1!=NULL){
            first=first*10+current1->data;
            current1=current1->next;
        }
        if(current2!=NULL){
        second=second*10+current2->data;
        current2=current2->next;
        }
    }
    int add=first+second;
    node* temp=NULL;
    int re=0;
    while(add!=0){
         re=add%10;
        push(temp,re);
        add=add/10;
    }

    return reverse(temp);
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
    node* head2=NULL;
    push(head2,1);
    push(head2,2);
    display(head);
    node* ans=addTwoLL(head,head2);
    display(ans);
    return 0;
}