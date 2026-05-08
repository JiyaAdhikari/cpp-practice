#include<iostream>
using namespace std;
#include<stack>

//queue using stack
class Queue{
public:
   stack<int> s1,s2;

   void push(int x){
    s1.push(x);
   }
   
   int front(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();
   }

   void pop(){
    if(s1.empty() && s2.empty()){
       return;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
   }

};

int main(){
 Queue q;

 q.push(11);
 q.push(22);
 q.push(33);
 for(int i=0;i<3;i++){
 cout<<q.front()<<" ";
 q.pop();
 }

}