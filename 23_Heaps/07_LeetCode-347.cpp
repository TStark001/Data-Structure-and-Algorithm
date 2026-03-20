/*
#   LeetCode-347 :- Top K frequent elements
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Example 2:
    Input: nums = [1], k = 1
    Output: [1]

    Example 3:
    Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
    Output: [1,2]
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

typedef pair<int,int> p; // this will create a pair also called macro
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int,int> m;
    // map pair is <ele,freq>
    for(int i = 0 ; i<nums.size() ; i++){
        m[nums[i]]++;
    }
    // heap pair is <freq,ele>
    priority_queue<p,vector<p>,greater<p>> pq;
    for(auto x : m){
        int ele = x.first;
        int freq = x.second;
        pq.push({freq,ele});
        if(pq.size()>k) pq.pop();
    }
    while(pq.size()>0){
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    vector<int> result = topKFrequent(nums,k);
    for(auto x : result){
        cout<<x<<" ";
    }
}