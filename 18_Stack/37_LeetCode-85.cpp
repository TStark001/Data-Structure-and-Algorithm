/*
#   LeetCode-85 :- Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    int nsi[n]; // nsi -> next smallest index
    stack<int> st;
    nsi[n-1] = n;
    st.push(n-1);
    for(int i = n-2 ; i>=0 ; i--){
        while(st.size()>0 and arr[st.top()]>=arr[i]) st.pop();
        if(st.size()==0) nsi[i] = n;
        else nsi[i] = st.top();
        st.push(i);
    }

    int psi[n]; // psi -> previous smallest index
    stack<int> gt;
    psi[0] = -1;
    gt.push(0);
    for(int i = 1 ; i<n ; i++){
        while(gt.size()>0 and arr[gt.top()]>=arr[i]) gt.pop();
        if(gt.size()==0) psi[i] = -1;
        else psi[i] = gt.top();
        gt.push(i);
    }

    int maxArea = 0;
    for(int i = 0 ; i<n ; i++){
        int height = arr[i];
        int breadth = nsi[i] - psi[i] -1;
        int area = height*breadth;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> height(col, 0);
    int maxArea = 0;
    for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j<col ; j++){
            if(matrix[i][j] == '1') height[j] += 1;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea , area);
    }
    return maxArea;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                   {'1','0','1','1','1'},
                                   {'1','1','1','1','1'},
                                   {'1','0','0','1','0'}};
    cout<<maximalRectangle(matrix);
}