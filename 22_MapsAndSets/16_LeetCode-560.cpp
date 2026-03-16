/*
#   LeetCode-560 :- Subarray Sum Equals k
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:
    Input: nums = [1,1,1], k = 2
    Output: 2

    Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums , int k){
    int n = nums.size();
    vector<int> pre(n);
    pre[0] = nums[0];
    for(int i = 1 ; i<n ; i++){
        pre[i] = nums[i] + pre[i-1];
    }
    unordered_map<int,int> m;
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        if(pre[i]==k) count++;
        int rem = pre[i] - k;
        if(m.find(rem)!=m.end()) count += m[rem];
        m[pre[i]]++;
    }
    return count;
}

int main(){
    vector<int> nums = {0,0,0,0};
    int k = 0;
    cout<<"Total No. of Subarray who sum is k = "<<subarraySum(nums,k);
}