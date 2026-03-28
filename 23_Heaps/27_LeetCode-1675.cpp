/*
#   LeetCode-1675 :- Minimize Deviation in Array
    You are given an array nums of n positive integers.
    You can perform two types of operations on any element of the array any number of times:
    If the element is even, divide it by 2.
    For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
    If the element is odd, multiply it by 2.
    For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
    The deviation of the array is the maximum difference between any two elements in the array.

    Return the minimum deviation the array can have after performing some number of operations.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: 1
    Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

    Example 2:
    Input: nums = [4,1,5,20,3]
    Output: 3
    Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

    Example 3:
    Input: nums = [2,10,8]
    Output: 3
!               Time Complexity :- O(nlog n)    ;   Space Complexity :- O(n)
*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int minimumDeviation(vector<int>& nums){
    int n = nums.size();
    vector<int> arr;
    for(int i = 0 ; i<n ; i++){
        if(nums[i]%2!=0) arr.push_back(nums[i]*2);
        else arr.push_back(nums[i]);
    }
    int minDev = INT_MAX;
    priority_queue<int> pq;
    int minEle = INT_MAX;
    for(auto x : arr){
        pq.push(x);
        minEle = min(minEle,x);
    }
    while(pq.size()>0){
        int maxEle = pq.top();
        pq.pop();
        if(maxEle%2 == 0){
            minDev = min(minDev,maxEle-minEle);
            pq.push(maxEle/2);
            minEle = min(minEle,maxEle/2);
        }
        else{
            minDev = min(minDev,maxEle-minEle);
            break;
        }
    }
    return minDev;
}

int main(){
    vector<int> nums = {4,1,5,20,3};
    cout<<"Minimum Deviation = "<<minimumDeviation(nums);   
}