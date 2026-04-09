/*
#   LeetCode-2357 :- Make Array Zero by Subtracting Equal Amounts
*/
#include<iostream>
#include<vector>
#include<climits>
#include<unordered_set>
using namespace std;

int minimumOperations(vector<int>& nums){
    unordered_set<int> s;
    for(auto x : nums){
        if(x > 0) s.insert(x);
    }
    return s.size();
}

int main(){
    vector<int> nums = {1,5,0,3,5};
    cout<<minimumOperations(nums);
}