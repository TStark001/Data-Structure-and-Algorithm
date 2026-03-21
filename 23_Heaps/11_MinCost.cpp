// Minimum cost to connect all ropes
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int minCost(vector<int>& arr){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto x : arr){
        pq.push(x);
    }
    int cost = 0;
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        pq.push(x+y);
        cost += x+y;
    }
    return cost;
}

int main(){
    vector<int> arr = {2,7,4,1,8};
    cout<<"Minimum Cost = "<<minCost(arr);
}