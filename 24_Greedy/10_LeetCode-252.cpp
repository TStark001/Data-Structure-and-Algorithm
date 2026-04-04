/*
#   LeetCode-252 :- Meeting Rooms
    Given an array of meeting time intervals intervals where intervals[i] = [start, end], determine if a person could attend all meetings.

    Example 1:
    Input: intervals = [[0,30], [5,10], [15,20]]
    Output: false

    Example 2:
    Input: intervals = [[7,10], [2,4]]
    Output: true
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals){
    if(intervals.size() == 0) return true;
    vector<int> start , endi;
    for(auto ele : intervals){
        start.push_back(ele[0]);
        endi.push_back(ele[1]);
    }
    sort(start.begin(),start.end());
    sort(endi.begin(),endi.end());
    int ans = 0;
    int rooms = 0;
    int i = 0 , j = 0;
    while(i < start.size() and j < endi.size()){
        if(start[i] < endi[j]){
            // a meeting is starting
            rooms++;
            ans = max(ans,rooms);
            i++;
        }
        else if(start[i] > endi[j]){
            // a meeting is ending
            rooms--;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    return ans == 1;
}

int main(){
    vector<vector<int>> interval = {{0,30},{5,10},{15,20}};
    if(canAttendMeetings(interval) == 1) cout<<"True";
    else cout<<"False";
}