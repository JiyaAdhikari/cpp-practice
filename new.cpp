#include<iostream>
using namespace std;

//circularly list

class Node{
   public:
 int data;
 Node* next;
};

//insert at start
void push_front(Node*& head,int val){

Node* newNode= new Node();
newNode->data=val;

if(head==NULL){
   head=newNode;
   newNode->next=head;
   return;
}

Node* temp=head;

while(temp->next!=head){
   temp=temp->next;
}

newNode->next=head;
temp->next=newNode;

head=newNode;
}

//insert at back
void push_back(Node*& head,int val){

Node* newNode= new Node();
newNode->data=val;

if(head==NULL){

   head=newNode;
   newNode->next=head;
   return;
}

Node* temp=head;

while(temp->next!=head){
   temp=temp->next;
}

temp->next=newNode;
newNode->next=head;

}

//delete at back
void pop_back(Node*& head){

   if(head==NULL){
      return;
   }
   if(head->next==head){
      delete head;
      head=NULL;
      return;
   }

   Node* temp=head;

   while(temp->next!=head){
      temp=temp->next;
   }

   Node* last=temp->next;
   temp->next=head;
   delete last;
}

//delete fisrt
void pop_front(Node*&head){

   if(head==NULL){
      return;
   }
   if(head->next==head){
      delete head;
      head=NULL;
      return;
   }
   Node* last=head;
   while(last->next!=head){
      last=last->next;
   }

   Node* temp=head;

   head=head->next;
   last->next=head;

   delete temp;
}

//insert at any pos
void Insert(Node*&head,int val,int pos){
   Node* newNode= new Node();
   newNode->data=val;

   if(pos==1){
      push_front(head,val);
   }
   Node* temp=head;

   for(int i=1;i<pos-1;i++){
      temp=temp->next;
   }
   if(temp==NULL){
      return;
   }

   newNode->next=temp->next;
   temp->next=newNode;
}

//delete at any pos
void Delete(Node*& head,int pos){
  
   if(pos==1){
      pop_front(head);
   }

   Node* temp=head;

   for(int i=1;i<pos-1;i++){
      temp=temp->next;
   }
   if(temp->next==NULL){
      return;
   }
   Node* toDelete=temp->next;
   temp->next=temp->next->next;
   delete toDelete;
}

//print
void print(Node*head){
 if(head==NULL){
   return;
 }
 Node* temp=head;

 do{
   cout<<temp->data<<" ";
   temp=temp->next;
 }while(temp!=head);
}

int main(){
   Node* head=NULL;
   
   push_back(head,1);
   push_back(head,2);
   push_back(head,3);
   push_back(head,4);
   
   print(head);
   cout<<endl;
   Insert(head,6,2);
   print(head);
   cout<<endl;
   pop_front(head);
   print(head);
   return 0;
}