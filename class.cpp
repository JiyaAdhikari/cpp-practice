#include<iostream>
using namespace std;
#include<stack>
#include<queue>

int main(){

    cout<<"reverse using Q and S:";
    cout<<endl;
    queue<int> q;
    stack<int> s;

    q.push(10); 
    q.push(20);
    q.push(30); 

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    cout<<"reversed:";
    cout<<endl;

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<"palindrome using stack:";
    cout<<endl;
    string st;
    cout<<"string:";
    cin>>st;

    stack<char> str;

    for(int i=0;i<st.length();i++){
        str.push(st[i]);
    }

    string r="";

    while(!str.empty()){
        r+=str.top();
        str.pop();

    }

    if(st==r){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }

    return 0;

}