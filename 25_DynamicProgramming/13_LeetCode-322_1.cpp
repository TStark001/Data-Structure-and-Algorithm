/*
#   LeetCode-322 :- Coin Change
    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

    Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

    Example 2:
    Input: coins = [2], amount = 3
    Output: -1

    Example 3:
    Input: coins = [1], amount = 0
    Output: 0
$                       Recursion + Memoization
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> dp;
int solve(vector<int>& coins, int x) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];

    int result = INT_MAX;

    for (int i = 0; i < coins.size(); i++) {
        if (x - coins[i] >= 0) {
            int sub = solve(coins, x - coins[i]);
            if (sub != INT_MAX) {
                result = min(result, 1 + sub);
            }
        }
    }
    return dp[x] = result;
}
int coinChange(vector<int>& coins, int amount) {
    dp.resize(amount + 1, -1);
    int ans = solve(coins, amount);
    // return (ans == INT_MAX ? -1 : ans);
    //          OR
    if (ans == INT_MAX) return -1;  
    return ans;
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<coinChange(coins,amount);
}