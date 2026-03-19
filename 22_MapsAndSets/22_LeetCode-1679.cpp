#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxOperations(vector<int>& nums , int k){
    int n = nums.size();
    unordered_map<int,int> m;
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        int rem = k - nums[i];
        if(m[rem]>0){
            count++;
            m[rem]--;
        }
        else m[nums[i]]++;
    }
    return count;
}

int main(){
    vector<int> nums = {3,5,1,5};
    int k = 2;
    cout<<"No. of Operation = "<<maxOperations(nums,k);
}