/*
#   LeetCode-378 :- Kth Smallest Element in a Sorted Matrix
    Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
    Note that it is the kth smallest element in the sorted order, not the kth distinct element.
    You must find a solution with a memory complexity better than O(n2).

    Example 1:
    Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
    Output: 13
    Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

    Example 2:
    Input: matrix = [[-5]], k = 1
    Output: -5
*/
#include <bits/stdc++.h>
using namespace std;


int kthSmallest(vector<vector<int>>& matrix, int k){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < matrix.size(); i++){
        pq.push({matrix[i][0], i, 0});
    }
    int val = 0;
    while(k > 0){
        auto ele = pq.top();
        pq.pop();
        val = ele[0];
        int r = ele[1];
        int c = ele[2];
        if(c + 1 < matrix[0].size()){
            pq.push({matrix[r][c + 1], r, c + 1});
        }
        k--;
    }
    return val;
}


int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;
    cout<<"Kth smallest element: "<<kthSmallest(matrix,k);
    return 0;
}