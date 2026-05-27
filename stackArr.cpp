#include<iostream>
using namespace std;

class Stack{
    public:
      int arr[5];
      int topIndex;

      Stack(){
        topIndex=-1;
      }

      //push

      void push(int val){
        
        if(topIndex==4){
            return;
        }

        topIndex++;
        arr[topIndex]=val;
      }

      //pop

      void pop(){

        if (topIndex==-1)
        {
           return;
        }

        topIndex--;
      }

      //top

      int top(){

        if(topIndex==-1){
            return -1;
        }
        return arr[topIndex];
      }

      //size

      int size(){
        return topIndex+1;
      }

      //empty

      bool empty(){
        if(topIndex==-1){
            return true;
        }
        return false;
      }

      //print

      void print(){
        if(topIndex==-1){
            cout<<"empty";
            return;
        }
        for(int i=topIndex;i>=0;i--){
           cout<<arr[i]<<" ";
        }
        cout<<endl;
      }
};

int main(){
    Stack s;
    
    s.push(5);

    cout<<"size:";
    cout<<s.size()<<endl;

    s.push(10);

    cout<<"top E:";
    cout<<s.top()<<endl;
    
    s.push(15);

    s.print();

    for(int i=0;i<3;i++){
        s.pop();
    }

    cout << s.empty() << endl; //1 is true
}