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

void interSect(node* head1,node* head2,int pos){
    node* current1=head1;
    node* current2=head2;
    int counter=0;
    while(current1!=NULL){
        if(counter==pos){
            break;
        }
        counter++;
        current1=current1->next;
    }
    while(current2->next!=NULL){
        current2=current2->next;
    }
    current2->next=current1;

}

void push(node* &head,int data){
    node* current=head;
    node* newNode=new node(data);
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
    }cout<<"NULL"<<endl;
}
int length(node* head){
    node* current=head;
    int counter=0;
    while(current!=NULL){
        current=current->next;
        counter++;
    }
    return counter;
}
int intersection(node* head1,node* head2){
    int counter=0;
    int len1=length(head1);
    int len2=length(head2);
    node* current1=head1;
    node* current2=head2;
    while(current1!=NULL){
        if(counter==len1-len2){
            break;
        }
        current1=current1->next;
        counter++;
    }

    while(current1!=NULL and current2!=NULL){
        if(current1==current2){
            return 1;
        }
        current1=current1->next;
        current2=current2->next;
    }
    return -1;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    push(head1,1);
    push(head1,2);
    push(head1,3);
    push(head1,4);
    push(head1,5);
    display(head1);
    push(head2,1);
    push(head2,2);
    display(head2);
    interSect(head1,head2,3);
    display(head2);
    display(head1);
    int ans=intersection(head1,head2);
    if(ans==-1){
        cout<<"intersection is not exists"<<endl;
    }else{
        cout<<"intersection is exists"<<endl;
    }
return 0;
}