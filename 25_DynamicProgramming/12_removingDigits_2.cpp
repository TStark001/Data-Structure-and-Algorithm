/*
#   Removing Digits
    You are given an integer n. On each step, you may subtract one of the digits from the number.
    How many step are required to make the number equal to 0?

    Input :- n = 27
    Output :- 5
    Explanation :- 27 -> 20 -> 18 -> 10 -> 9 -> 0
$                       Tabulation
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
int removingDigits(int num){
    dp[0] = 0;
    for(int i = 0 ; i <= 9 ; i++) dp[i] = 1;
    for(int n = 10 ; n <= num ; n++){
        // n -> state
        // calc  dp[n]
        vector<int> digits = getDigits(n);
        int result = INT_MAX;
        for(int i = 0 ; i < digits.size() ; i++){
            result = min(result , dp[n - digits[i]]);
        }
        dp[n] = 1 + result;
    }
    return dp[num];
}

int main(){ 
    int num = 27;
    dp.clear();
    dp.resize(num+1,-1);
    cout<<removingDigits(num);
}