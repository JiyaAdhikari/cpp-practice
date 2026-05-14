#include<iostream>
using namespace std;

//SINGLY LINKED LIST

class Node{
   public:
   int data;
   Node* next;
};

void push_front(Node*& head,int val){
   Node* newNode=new Node();
   newNode->data=val;
   newNode->next=NULL;
    
   if(head==NULL){
      head=newNode;
   }

   else{
      newNode->next=head;
      head=newNode;
   }
}

void push_back(Node*& head,int val){
   Node* newNode=new Node();
   newNode->data=val;
   newNode->next=NULL;

   if(head==NULL){
      head=newNode;
   }
   else{
      Node*temp=head;
      //transverse;
      while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next=newNode;
   }

}

void pop_front(Node*& head){

if(head==NULL){
   return;
}
Node*temp=head;
head=head->next;

delete temp;

}

void pop_back(Node*& head){
   if(head==NULL){
   return;
}
if(head->next==NULL){
   delete head;
   head=NULL;
   return;
}
Node*temp=head;
while(temp->next->next!=NULL){
   temp=temp->next;
}
delete temp->next;
temp->next=NULL;
}

void insert(Node*& head,int val,int pos){
    Node* newNode=new Node();
   newNode->data=val;
   newNode->next=NULL;

   if(pos==1){
      newNode->next=head;
      head=newNode;return;
   }
   Node*temp=head;
   for(int i=1;i<pos-1 && temp!=NULL;i++){
      temp=temp->next;
   }
   newNode->next=temp->next;
   temp->next=newNode;

}

void Delete(Node*& head,int val,int pos){
   Node*temp=head;
   if(pos==1){
      head=head->next;
      delete temp;
      return;
   }
  
   for(int i=1;i<pos-1 && temp!=NULL;i++){
      temp=temp->next;
   }
   Node* todelete=temp->next;
   temp->next=temp->next->next;
   delete todelete;
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
   push_back(head,10);
   push_back(head,20);
   push_back(head,30);

     print(head);
}