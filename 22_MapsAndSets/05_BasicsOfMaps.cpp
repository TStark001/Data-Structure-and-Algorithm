#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m;
    pair<string,int> p1;
    p1.first = "Stark";
    p1.second = 1;
    pair<string,int> p2;
    p2.first = "Flames";
    p2.second = 2;
    m.insert(p1);
    m.insert(p2);
    /*
    for(pair<string,int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    */
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"Size = "<<m.size();
    cout<<endl<<endl;
    //%     Second method to insert element in Maps
    m["Devil"] = 3;
    m["Jack Reacher"] = 4;
    m["John Wick"] = 5;
    m["James Bond"] = 7;
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"Size = "<<m.size();
    cout<<endl<<endl;
    m.erase("James Bond");
    m.erase("Jack Reacher");
    m.erase("Flames");
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"Size = "<<m.size()<<endl;
    cout<<m["Stark"];
}