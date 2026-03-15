#include<iostream>
#include<set>
#include<map>
using namespace std;

int main(){
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(7);
    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl<<endl;

    map<int,int> m;
    m[2] = 20;
    m[1] = 30;
    m[3] = 10;
    for(auto x : m){ // sorting is based on key value
        // cout<<x.first<<" ";
        cout<<x.second<<" ";
    }
}