#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1); 
    cout<<"Size of Sets = "<<s.size()<<endl;
    s.erase(2);
    // to print the unordered sets we use for each loop
    for(int x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"Size of Sets = "<<s.size()<<endl;
    int target = 4;
    /*
        s.find() -> it searches in the set , and if 
                    it is not found then it returns the last element
    */
    if(s.find(target)!=s.end()){ // target exist
        cout<<"Exist"<<endl;
    }
    else cout<<"Does Not Exist!"<<endl;
}