/*
#   LeetCode-767 :- Reorganize String
    Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
    Return any possible rearrangement of s or return "" if not possible.

    Example 1:
    Input: s = "aab"
    Output: "aba"

    Example 2:
    Input: s = "aaab"
    Output: ""
!       More Optimized
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

typedef pair<int,char> p;
string reorganizeString(string s){
    string res = "";
    unordered_map<char,int> m;  // <char,freq>
    for(auto ch : s){
        m[ch]++;
    }
    priority_queue<p> pq;   // <int,char> -> <freq,char>
    for(auto x : m){
        pq.push({x.second,x.first});
    }
    while(pq.size()>1){
        auto first = pq.top();
        pq.pop();
        auto second = pq.top();
        pq.pop();
        res += first.second;
        res += second.second;
        first.first--;
        second.first--;
        if(first.first>0) pq.push(first);
        if(second.first>0) pq.push(second);
    }
    if(pq.size() == 1){
        auto last = pq.top();
        if(last.first>1) return "";
        res += last.second;
    }
    return res;
}

int main(){
    string s = "aab";

    string ans = reorganizeString(s);

    if(ans == "") cout << "Not possible";
    else cout << ans;

    cout << endl;
}