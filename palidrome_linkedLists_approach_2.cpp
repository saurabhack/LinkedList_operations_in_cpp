#include<iostream>
#include<vector>
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
bool is_palidrome(node* head){
    vector<int> arr;
    node* current=head;
    while(current!=NULL){
        arr.push_back(current->data);
        current=current->next;
    }
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
int main(){
    node* head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    display(head);
    cout<<is_palidrome(head)<<endl;
return 0;
}
