#include<iostream>
using namespace std;

//code for middle element : slow->1 step , fast-> 2 steps

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

Node* findM(Node* head){

    Node* slow=head;
    Node* fast= head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
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
    cout<<endl;
    cout<<"the middle element is:";
    cout<<findM(head)->data;
}