/*
#   LeetCode-1636 :- Sort Array by increasing frequency
    Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

    Return the sorted array.

    Example 1:
    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

    Example 2:
    Input: nums = [2,3,1,3,2]
    Output: [1,3,3,2,2]
    Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

    Example 3:
    Input: nums = [-1,1,-6,4,5,-6,1,4,1]
    Output: [5,-1,4,4,-6,-6,1,1,1]
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int,int> m;
    // count frequency
    for(auto x : nums){
        m[x]++;
    }
    // custom comparator
    auto cmp = [&](int a , int b){
        if(m[a]==m[b]){
            return a<b ; // value ↓ (so max comes first)
        }
        return m[a] > m[b]; // freq ↑ (min comes first)
    };
    priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
    // push all element
    for(auto x : nums){
        pq.push(x);
    }
    vector<int> ans;
    while(pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> arr = {1,1,2,2,2,3};
    vector<int> ans = frequencySort(arr);
    for(auto x : ans){
        cout<<x<<" ";
    }
}