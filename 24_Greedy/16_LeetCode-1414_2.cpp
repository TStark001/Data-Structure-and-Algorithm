/*
#   LeetCode-1414 :- Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
    Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.

    The Fibonacci numbers are defined as:

    F1 = 1
    F2 = 1
    Fn = Fn-1 + Fn-2 for n > 2.
    It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.

    Example 1:
    Input: k = 7
    Output: 2 
    Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
    For k = 7 we can use 2 + 5 = 7.

    Example 2:
    Input: k = 10
    Output: 2 
    Explanation: For k = 10 we can use 2 + 8 = 10.

    Example 3:
    Input: k = 19
    Output: 3 
    Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMinFibonacciNumbers(int k) {
    int first = 1;
    int second = 1;

    // Step 1: Find largest Fibonacci ≤ k
    while (second <= k) {
        int third = first + second;
        first = second;
        second = third;
    }

    int count = 0;

    // Step 2: Greedy subtraction
    while (k > 0) {
        if (first <= k) {
            k -= first;
            count++;
        }
        int third = second - first; // move backward
        second = first;
        first = third;
    }

    return count;
}

int main(){
    int k = 10;
    cout<<findMinFibonacciNumbers(k);
}