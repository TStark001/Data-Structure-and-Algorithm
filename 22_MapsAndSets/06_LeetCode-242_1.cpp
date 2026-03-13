/*
#   LeetCode-242 :- Valid Anagram
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:
    Input: s = "rat", t = "car"
    Output: false
*/
#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> map1; // for s
    unordered_map<char,int> map2; // for t
    for(int i = 0 ; i<s.length() ; i++){
        map1[s[i]]++;
    }
    for(int i = 0 ; i<t.length() ; i++){
        map2[t[i]]++;
    }
    for(auto x : map1){
        char ch1 = x.first;
        int freq1 = x.second;
        if(map2.find(ch1)!=map2.end()){
            int freq2 = map2[ch1];
            if(freq1!=freq2) return false;
        }
        else return false;
    }
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    if(isAnagram(s,t)==1) cout<<"True";
    else cout<<"False";
}