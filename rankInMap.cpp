#include<iostream>
#include<map>
#include<vector>
#include <algorithm>
using namespace std;

int main(){

    //store RANK in map

    vector <int> arr={40,10,30,20};
    vector <int> temp=arr;

    sort(temp.begin(),temp.end());

    map<int,int> rank;

    for(int i=0;i<temp.size();i++){
        rank[temp[i]]=i+1;
    }
    
    //replace elemts

    for(int i=0;i<arr.size();i++){
        arr[i]=rank[arr[i]];
    }
    
    vector<int> :: iterator it;

    for(it= arr.begin(); it!= arr.end(); it++){
        cout<<*it<<" ";
    }

    cout<<endl;
    cout<<endl; 

    //frequency 

    vector<int> a={1,2,3,4,4,4,4,5,5,30,30};

    map<int,int> freq;
    
    //count

    for(int i=0;i<a.size();i++){
        freq[a[i]]++;
    }

    map<int,int> :: iterator i;

    for(i=freq.begin(); i != freq.end(); i++){
        cout<< i->first<< "->" << i->second<<endl;
    }
    return 0;
}