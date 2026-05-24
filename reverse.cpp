#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;
};

void push_back(Node*& head,int val){

    Node* newNode=new Node();
   newNode->data=val;
   newNode->next=NULL;

   if(head==NULL){
    head=newNode;
    return;
   }

   Node* temp=head;

   while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next=newNode;
}

//reverse

void reverse(Node*& head){
    Node* prev=NULL;
    Node* current=head;
    Node* next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void print(Node*& head){
   Node*temp=head;

   while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;

   }
}

int main(){
     Node* head=NULL;

    push_back(head,11);
    push_back(head,22);
    push_back(head,33);
    push_back(head,44);
    push_back(head,55);

    print(head);

    reverse(head);
    cout<<endl;
    print(head);

}