/*
#   Minimum Cost to cut a board into square
    A board of length M and width N is given.The task is to break this board into M*N squares such
    that cost of breaking is minimum.The cutting cost for each edge will be given for the board in
    two array X and array Y.In short you need to choose such a sequence of cutting such that cost is
    minimized.Return the minimized cost.

    Input :- M = 6 , N = 4
            X = [2,1,3,1,4] , Y = [4,1,2]
    Output :- 42
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

bool cmp(int x , int y){
    return x > y;
}
ll minCostToBreakGrid(int m , int n ,vector<ll>& vertical , vector<ll>& horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz = 1; // count of horizontal
    int vr = 1; // count of vertical
    int h = 0 , v = 0;
    ll ans = 0;
    while(h < horizontal.size() and v < vertical.size()){
        if(vertical[v] > horizontal[h]){
            ans += vertical[v]*vr;
            hz++;
            v++;
        }
        else{
            ans += horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while(h < horizontal.size()){
        ans += horizontal[h]*hz;
        vr++;
        h++;
    }
    while(v < vertical.size()){
        ans += vertical[v]*vr;
        hz++;
        v++;
    }
    return ans;
}

int main(){
    int m = 6 , n = 4;
    vector<ll> vertical = {2,1,3,1,4};
    vector<ll> horizontal = {4,1,2};
    cout<<minCostToBreakGrid(m,n,vertical,horizontal);
}