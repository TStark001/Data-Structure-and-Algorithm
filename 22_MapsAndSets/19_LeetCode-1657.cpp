/*
#   LeetCode-1657 :- Determine if Two Strings Are Close
    Two strings are considered close if you can attain one from the other using the following operations:

    Operation 1: Swap any two existing characters.
    For example, abcde -> aecdb
    Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
    For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
    You can use the operations on either string as many times as necessary.

    Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

    Example 1:
    Input: word1 = "abc", word2 = "bca"
    Output: true
    Explanation: You can attain word2 from word1 in 2 operations.
    Apply Operation 1: "abc" -> "acb"
    Apply Operation 1: "acb" -> "bca"

    Example 2:
    Input: word1 = "a", word2 = "aa"
    Output: false
    Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

    Example 3:
    Input: word1 = "cabbba", word2 = "abbccc"
    Output: true
    Explanation: You can attain word2 from word1 in 3 operations.
    Apply Operation 1: "cabbba" -> "caabbb"
    Apply Operation 2: "caabbb" -> "baaccc"
    Apply Operation 2: "baaccc" -> "abbccc"
*/
#include<iostream>
#include<unordered_map>
using namespace std;

bool closeStrings(string str1, string str2) {
    if(str1.length()!=str2.length()) return false;
    unordered_map<char,int> m1 , m2;
    for(int i = 0 ; i<str1.length() ; i++){
        m1[str1[i]]++;
        m2[str2[i]]++;
    }
    // comparing map1 and map2 (only charaters)
    for(auto x : m1){
        char ch = x.first;
        if(m2.find(ch)==m2.end()) return false;
    }
    unordered_map<int,int> h1 , h2;
    for(auto x : m1){
        int freq = x.second;
        h1[freq]++;
    }
    for(auto x : m2){
        int freq = x.second;
        h2[freq]++;
    }
    // comparing helper1 and helper2 maps
    for(auto x : h1){
        int key = x.first;
        if(h2.find(key)==h2.end()) return false;
        if(h2[key]!=h1[key]) return false;
    }
    return true;
}

int main(){
    string str1 = "cabbba";
    string str2 = "abbccc";
    if(closeStrings(str1,str2) == 1) cout<<"True";
    else cout<<"False";
}