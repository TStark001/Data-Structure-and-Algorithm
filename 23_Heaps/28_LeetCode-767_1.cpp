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
    priority_queue<p> pq;
    for(auto x : m){
        pq.push({x.second,x.first});
    }
    while(pq.size()>1){
        int firstFreq = pq.top().first;
        char firstCh = pq.top().second;
        pq.pop();
        int secondFreq = pq.top().first;
        char secondCh = pq.top().second;
        pq.pop();
        res += firstCh;
        res += secondCh;
        firstFreq--;
        secondFreq--;
        if(firstFreq>0) pq.push({firstFreq,firstCh});
        if(secondFreq>0) pq.push({secondFreq,secondCh});
    }
    if(pq.size() == 1){
        int lastFreq = pq.top().first;
        char lastCh = pq.top().second;
        if(lastFreq>1) return "";
        res += lastCh;
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