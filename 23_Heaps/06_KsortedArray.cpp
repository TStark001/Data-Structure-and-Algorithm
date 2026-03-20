// Sort a K sorted Array(sort a nearly sorted array)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> sortArray(vector<int>& nums , int k){
    int idx = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0 ; i<nums.size() ; i++){
        pq.push(nums[i]);
        if(pq.size()>k){
            nums[idx++] = pq.top();
            pq.pop();
        }
    }
    while(pq.size()>0){
        nums[idx++] = pq.top();
        pq.pop();
    }
    return nums;
}
//!     Time Complexity :- O(nlogK)
int main(){
    vector<int> nums = {6,5,3,2,8,10,9};
    int k = 3;
    cout<<"Befor Sorting :- ";
    for(auto x : nums){
        cout<<x<<" ";
    }
    vector<int> result = sortArray(nums,k);
    cout<<endl<<"After Sorting :- ";
    for(auto x : result){
        cout<<x<<" ";
    }
}