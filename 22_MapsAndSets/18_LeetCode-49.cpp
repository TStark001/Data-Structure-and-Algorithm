/*
#   LeetCode-49 :- Group Anagrams
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    Explanation:
    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

    Example 2:
    Input: strs = [""]
    Output: [[""]]

    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& arr){
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> m;
    for(string str : arr){
        string lexo = str;
        sort(lexo.begin(),lexo.end());
        if(m.find(lexo)==m.end()){
            vector<string> v;
            v.push_back(str);
            m[lexo] = v;
        }
        else{
            m[lexo].push_back(str);
        }
    }
    for(auto x : m){
        vector<string> v = x.second;
        ans.push_back(v);
    }
    return ans;
}

int main(){
    vector<string> arr = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(arr);
    for(auto group : result){
        cout << "[ ";
        for(auto word : group){
            cout << word << " ";
        }
        cout << "]" << endl;
    }
}