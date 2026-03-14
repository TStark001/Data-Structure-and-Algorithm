/*
#   LeetCode-1207 :- Unique Number of Occurrences
    Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

    Example 1:
    Input: arr = [1,2,2,1,1,3]
    Output: true
    Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

    Example 2:
    Input: arr = [1,2]
    Output: false

    Example 3:
    Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
    Output: true
*/
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

bool uniqueOccurrences(vector<int>& arr){
    int n = arr.size();
    unordered_map<int,int> m;
    for(int i = 0 ; i<n ; i++){
        m[arr[i]]++;
    }
    unordered_set<int> s;
    for(auto x : m){
        int freq = x.second;
        if(s.find(freq)!=s.end()) return false;
        else s.insert(freq);
    }
    return true;
}

int main(){
    vector<int> arr = {1,2,2,1,1,3};
    if(uniqueOccurrences(arr) == 1) cout<<"True";
    else cout<<"False";
}