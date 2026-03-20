#include<iostream>
#include<queue>
using namespace std;

int main(){
    // in c++ by default maxHeap is created
    priority_queue<int> pq; 
    pq.push(10);
    pq.push(2);
    pq.push(-6);
    pq.push(8);
    cout<<"Top Most ele = "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top Most ele = "<<pq.top()<<endl;
}