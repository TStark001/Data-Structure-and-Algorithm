/*
#   LeetCode-1122 :- Relative Sort Array
    Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

    Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

    Example 1:
    Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    Output: [2,2,2,1,4,3,3,9,6,7,19]

    Example 2:
    Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
    Output: [22,28,8,6,17,44]
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1 , vector<int>& arr2){
    vector<int> ans;
    unordered_map<int,int> m;
    for(int i = 0 ; i<arr1.size() ; i++){
        m[arr1[i]]++;
    }
    // place elements according to arr2
    for(int i = 0 ; i < arr2.size() ; i++){
        while(m[arr2[i]] > 0){
            ans.push_back(arr2[i]);
            m[arr2[i]]--;
        }
    }
    vector<int> temp;
    for(auto x : m){
        while(x.second > 0){
            temp.push_back(x.first);
            x.second--;
        }
    }
    sort(temp.begin(),temp.end());
    for(auto x : temp){
        ans.push_back(x);
    }
    return ans;
}

int main(){
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> result = relativeSortArray(arr1,arr2);
    for(auto x : result){
        cout<<x<<" ";
    }
}