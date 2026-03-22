/*
    Convert non-sorted array into minheap and print in the form of array
    1-based indexing

    in array -1 is dummy value
*/
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& arr,int n){
    for(int i = 0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapify(int i , vector<int>& arr , int n){
    while(true){
        int left = 2*i , right = 2*i+1;
        if(left>=n) break;
        if(right>=n){
            if(arr[i]>arr[left]){
                swap(arr[i],arr[left]);
                i = left;
            }
            break;
        }
        if(arr[left]<arr[right]){
            if(arr[i]>arr[left]){
                swap(arr[i],arr[left]);
                i = left;
            }
            else break;
        }
        else{
            if(arr[i]>arr[right]){
                swap(arr[i],arr[right]);
                i = right;
            }
            else break;
        }
    }
}

int main(){
    vector<int> arr = {-1,10,2,14,11,1,4};
    int n = arr.size();
    print(arr,n);
    for(int i = n/2 ; i>=1 ; i--){
        heapify(i,arr,n);
    }
    print(arr,n);
}