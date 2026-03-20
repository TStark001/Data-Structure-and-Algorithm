#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    // minHeap --> smallest element on the top
    priority_queue<int,vector<int>,greater<int>> pq; 
    pq.push(10);
    pq.push(2);
    pq.push(-6);
    pq.push(8);
    cout<<"Top Most ele = "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top Most ele = "<<pq.top()<<endl;
}