#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> arr = {10,20,-4,5,18,24,1,-7,56};
    int n = arr.size();
    int k = 4;
    priority_queue<int> pq; // maxHeap
    for(int i = 0 ; i<n ; i++){ // T.C :- O(n*log k)    S.C = O(n)  Auxiliary Space = O(K)
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<"Kth Smallest Element :- "<<pq.top();
}