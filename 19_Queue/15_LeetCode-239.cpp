/*
#   LeetCode-239 :- Sliding Window Maximum
    You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

    Return the max sliding window.

    Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
*/
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums , int k){
    if(k==1) return nums;
    int n = nums.size();
    deque<int> dq; // decreasing order of ele(index)
    vector<int> ans; // i should be min k-1
    for(int i = 0 ; i<n ; i++){
        while(dq.size()>0 and nums[i]>nums[dq.back()]) dq.pop_back();
        dq.push_back(i);
        int j = i-k+1; // start of the window
        while(dq.front()<j) dq.pop_front();
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    } 
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> ans = maxSlidingWindow(nums,k);
    for(int y : ans){
        cout<<y<<" ";
    }
    return 0;
}