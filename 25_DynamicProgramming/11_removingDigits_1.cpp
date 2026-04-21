/*
#   Removing Digits
    You are given an integer n. On each step, you may subtract one of the digits from the number.
    How many step are required to make the number equal to 0?

    Input :- n = 27
    Output :- 5
    Explanation :- 27 -> 20 -> 18 -> 10 -> 9 -> 0
$                       Recursion + Memoization
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> getDigits(int n){
    vector<int> result;
    while(n > 0){
        if(n % 10 != 0){
            // n % 10 is last digit
            result.push_back(n % 10);
        }
        n = n / 10;
    }
    return result;
}
vector<int> dp;
int removingDigits(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> digits = getDigits(n);
    int result = INT_MAX;
    for(int i = 0 ; i < digits.size() ; i++){
        result = min(result , removingDigits(n - digits[i]));
    }
    return dp[n] = 1 + result;
}

int main(){
    int n = 27;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<removingDigits(n);
}