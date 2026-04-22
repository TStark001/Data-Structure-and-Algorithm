/*
#   LeetCode-1155 :- Number of Dice Rolls with Target Sum
    You have n dice, and each dice has k faces numbered from 1 to k.

    Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

    Example 1:
    Input: n = 1, k = 6, target = 3
    Output: 1
    Explanation: You throw one die with 6 faces.
    There is only one way to get a sum of 3.

    Example 2:
    Input: n = 2, k = 6, target = 7
    Output: 6
    Explanation: You throw two dice, each with 6 faces.
    There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

    Example 3:
    Input: n = 30, k = 30, target = 500
    Output: 222616187
    Explanation: The answer must be returned modulo 109 + 7.
$           Recursion + Memoization
*/
#include<iostream>
#include<vector>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<vector<int>> dp;
int helper(int n , int k , int t){
    if(n == 0 and t == 0) return 1;
    if(n == 0) return 0;
    if(dp[n][t] != -1) return dp[n][t];
    int sum = 0;
    for(int v = 1 ; v <= k ; v++){
        if(t-v < 0) continue;   
        sum = ((sum % mod) + helper(n-1 , k , t-v) % mod);
    }
    return dp[n][t] = sum % mod;
}
int numRollsToTarget(int n, int k, int target) {
    dp.clear();
    dp.resize(35,vector<int> (1005,-1));
    return helper(n , k , target);
}

int main(){
    int n = 30 , k = 30 , target = 500;
    cout<<numRollsToTarget(n,k,target);
}