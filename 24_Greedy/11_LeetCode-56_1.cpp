/*
#   LeetCode-56 :- Merge Interval
    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

    Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

    Example 2:
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    Example 3:
    Input: intervals = [[4,7],[1,4]]
    Output: [[1,7]]
    Explanation: Intervals [1,4] and [4,7] are considered overlapping.
!                       Method-1 (from last index)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int>& a , vector<int>& b){
    return a[1] < b[1];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp);
    vector<vector<int>> result;
    int n = intervals.size();
    result.push_back(intervals[n-1]); // right -> left
    for(int i = n-2 ; i >= 0 ; i--){
        vector<int> curr = intervals[i];
        if(curr[1] >= result[result.size() - 1][0]){
            // curr.end >= last.start -> overlapping
            result[result.size() - 1][0] = min(result[result.size() - 1][0],curr[0]);
            result[result.size() - 1][1] = max(result[result.size() - 1][1],curr[1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals);
    for(auto x : result){
        for(auto val : x){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}