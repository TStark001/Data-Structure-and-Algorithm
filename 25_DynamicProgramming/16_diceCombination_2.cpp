/*
#   Dice Combination
    Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
    Each throw produces an outcome between 1 and 6.

    For example , if n = 3 , there are 4 ways:
        . 1 + 1 + 1 
        . 1 + 2
        . 2 + 1
        . 3
    
    Input :- The only input line has an integer n

    Output :- Print the number of ways modulo 10^9 + 7
    
    Example:-
    Input :- 3
    Output :- 4
$               Tabulation
*/
#include<iostream>
#include<vector>
#define mod 1000000007  
#define ll long long int
using namespace std;

vector<ll> dp;
ll noOfWays(int n){
    dp[0] = 1;
    for(int k = 1 ; k <= n ; k++){
        ll sum = 0;
        for(int i = 1 ; i<= 6 ; i++){
            if(k - i < 0) break;
            sum = (sum % mod + dp[k-i] % mod) % mod;
        }
        dp[k] = sum % mod;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5 , -1);
    cout<<noOfWays(n);
}