#include<iostream>
using namespace std;

//DOUBLY LINKED LIST

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

//insert at beginning

void push_front(Node*& head,int val){

    Node* newNode= new Node();
    newNode->data=val;
     newNode->prev=NULL;
     newNode->next=head;

     if(head!=NULL){
        head->prev=newNode;
     }

     head=newNode;
}

//insert at end

void push_back(Node*& head,int val){

    Node* newNode=new Node();
     newNode->data=val;
     newNode->next=NULL;

     if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
     }
 
     Node* temp=head;
     while(temp->next!=NULL){
        temp=temp->next;
     }

     temp->next=newNode;
     newNode->prev=temp;
}

//delete first

void pop_front(Node*& head){

    if(head==NULL){
        return;
    }
    
    Node* temp=head;
    head=temp->next;

    if(head!=NULL){
        head->prev=NULL;
    }

    delete temp;
}

//delete last node

void pop_back(Node*& head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->prev->next=NULL;
    delete temp;
}

//print

void print(Node*& head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;

    push_back(head,1);
    push_back(head,2);
    push_back(head,3);
    push_back(head,4);

    print(head);  
    
    pop_back(head);
    cout<<endl;

    print(head);

    return 0;
}