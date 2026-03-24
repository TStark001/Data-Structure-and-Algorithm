/*
#   LeetCode-632 :- Smallest Range Covering Elements from K list
    You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

    We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

    Example 1:
    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    Output: [20,24]
    Explanation: 
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is in range [20,24].

    Example 2:
    Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    Output: [1,1]
*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int,pair<int,int>> p;
vector<int> smallestRange(vector<vector<int>>& arr) {
    priority_queue<p,vector<p>,greater<p>> pq;
    // pq element -> {arr[row][col],{row,col}}
    int mx = INT_MIN;
    for(int i = 0 ; i<arr.size() ; i++){
        mx = max(mx,arr[i][0]);
        pq.push({arr[i][0],{i,0}});
    }
    int mn = pq.top().first;
    int start = mn , end = mx;
    while(true){
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        if(col==arr[row].size()-1) break;
        pq.push({arr[row][col+1],{row,col+1}});
        mx = max(mx,arr[row][col+1]);
        mn = pq.top().first;
        if(mx-mn < end - start){
            end = mx;
            start = mn;
        }
    }
    return {start,end};
}

int main(){
    vector<vector<int>> arr = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> result = smallestRange(arr);
    for(auto x : result){
        cout<<x<<" ";
    }
}