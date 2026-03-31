/*
#   LeetCode-1005 :- Maximize Sum of Array After K Negations
    Given an integer array nums and an integer k, modify the array in the following way:

    choose an index i and replace nums[i] with -nums[i].
    You should apply this process exactly k times. You may choose the same index i multiple times.

    Return the largest possible sum of the array after modifying it in this way.

    Example 1:
    Input: nums = [4,2,3], k = 1
    Output: 5
    Explanation: Choose index 1 and nums becomes [4,-2,3].

    Example 2:
    Input: nums = [3,-1,0,2], k = 3
    Output: 6
    Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].

    Example 3:
    Input: nums = [2,-3,-1,5,-4], k = 2
    Output: 13
    Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int largestSumAfterNegations(vector<int>& nums,int k){      // Time Complexity :- O(Klog n + n)
    priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
    int sum = 0;
    for(int i = 0 ; i<nums.size() ; i++) sum += nums[i];
    while(k--){
        int ele = pq.top();
        if(ele == 0) break;
        pq.pop();
        sum -= ele;
        pq.push(-1*ele);
        sum += (-ele);
    }
    return sum;
}

int main(){
    vector<int> nums = {3,-1,0,2};
    int k = 3;
    cout<<"Largest Sum = "<<largestSumAfterNegations(nums,k);
}