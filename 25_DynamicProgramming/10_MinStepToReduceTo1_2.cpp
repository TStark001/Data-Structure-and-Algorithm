/*
    Given a number n , you can perform any of the following operation on it some no. of times
    1 -> Reduce n to n-1
    2 -> if n is divisible by 2 then make it n/2
    3 -> if n is divisible by 3 then make it n/3
    Find out in how many minimum step you can use to reduce n to 1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define inf INT_MAX
using namespace std;

//%         Tabulation
vector<int> dp;
int minStep(int n){
    dp.clear();
    dp.resize(n+1,-1);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i = 4 ; i <= n ; i++){
        dp[i] = 1 + min({dp[i-1] , (i%2 == 0) ? dp[i/2] : inf , (i%3 == 0) ? dp[i/3] : inf});
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<minStep(n);
}