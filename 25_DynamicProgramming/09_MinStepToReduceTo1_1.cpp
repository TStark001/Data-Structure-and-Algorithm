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

/*
    $       Recursive solution
    int minStep(int n){
        if(n == 1) return 0;
        if(n == 2 or n == 3) return 1;
        return 1 + min({minStep(n-1) , (n%2 == 0) ? minStep(n/2) : inf , (n%3 == 0) ? minStep(n/3) : inf});
    }
*/
//  %       Recursive + Memoization
vector<int> dp;
int minStep(int n){
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(dp[n] != -1) return dp[n]; // nth state is precomputed
    // if dp[n] is -1 , we need to compute first time this state
    return dp[n] = 1 + min({minStep(n-1) , (n%2 == 0) ? minStep(n/2) : inf , (n%3 == 0) ? minStep(n/3) : inf});
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<minStep(n);
}