/*
#   LeetCode-786 :- K-th Smallest Prime Fraction
    You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

    For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

    Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

    

    Example 1:

    Input: arr = [1,2,3,5], k = 3
    Output: [2,5]
    Explanation: The fractions to be considered in sorted order are:
    1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
    The third fraction is 2/5.
    Example 2:

    Input: arr = [1,7], k = 1
    Output: [1,7]
!                                Time Complexity :- O((n+k)log n) and Space Complexity :- O(n)
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    auto cmp = [&](pair<int,int>& a, pair<int,int>& b){
        return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

    // Step 1: push initial fractions
    for(int j = 1; j < n; j++){
        pq.push({0, j});
    }

    // Step 2: process k times
    while(k>1){
        auto top = pq.top();
        pq.pop();

        int i = top.first;
        int j = top.second;

        if(i + 1 < j) pq.push({i+1, j});
        k--;
    }

    // Step 3: answer
    auto top = pq.top();
    return {arr[top.first], arr[top.second]};
}

int main(){
    vector<int> arr = {1,2,3,5};
    int k = 3;
    vector<int> ans = kthSmallestPrimeFraction(arr,k);
    for(auto x : ans){
        cout<<x<<" ";
    }
}