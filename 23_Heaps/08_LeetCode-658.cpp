/*
#   LeetCode-658 :- Find K closest Element
    Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
    An integer a is closer to x than an integer b if:
    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b

    Example 1:
    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

    Example 2:
    Input: arr = [1,1,2,3,4,5], k = 4, x = -1
    Output: [1,1,2,3]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> p;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> ans;
    priority_queue<p> pq;
    for(int i = 0 ; i<arr.size() ; i++){
        int dis = abs(x-arr[i]);
        pq.push({dis,arr[i]});
        if(pq.size()>k) pq.pop();
    } 
    while(pq.size()>0){
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> nums = {1,1,2,3,4,5};
    int k = 4 , x = -1;
    vector<int> result = findClosestElements(nums,k,x);
    for(auto x : result){
        cout<<x<<" ";
    }
}