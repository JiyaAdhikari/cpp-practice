#include<iostream>
using namespace std;

class Queue{

    public:

    int arr[5];
    int frontIndex;
    int rearIndex;

    Queue(){

        frontIndex=0;
        rearIndex=-1;

    }
    
    void enqueue(int val){

        if(rearIndex==4){
            return;
        }

        rearIndex++;
        arr[rearIndex]=val;
    }

    void dequeue(){

        if(frontIndex>rearIndex){
            return;
        }

        frontIndex++;
    }

    int front(){

        if(frontIndex>rearIndex){
            return -1;
        }

        return arr[frontIndex];
    }

    int size(){

        return rearIndex-frontIndex+1;

    }

    void print(){

        for(int i=frontIndex;i<=rearIndex;i++){
             cout<<arr[i]<<" ";
        }

    }

};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);

    q.print();
    cout<<endl;

    cout<<"size:"<<q.size();
    cout<<endl;
    cout<<"frontE:"<<q.front();
     cout<<endl;

    q.dequeue();
    q.print();

    return 0;
}