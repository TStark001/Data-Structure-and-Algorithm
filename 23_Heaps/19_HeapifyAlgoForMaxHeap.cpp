/*
    Convert non-sorted array into maxHeap and print in the form of array
    0-based indexing

    Heapify Algorithm for MaxHeap
*/
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& arr){
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
}
void heapify(int i , vector<int>& arr , int n){
    while(true){
        int left = 2*i+1 , right = 2*i+2;
        if(left>=n) break; // left child not exits
        if(right>=n){ // left child exits but right child does not exits
            if(arr[i]<arr[left]){
                swap(arr[i],arr[left]);
                i = left;
            }
            break;
        }
        if(arr[left]>arr[right]){
            if(arr[i]<arr[left]){
                swap(arr[i],arr[left]);
                i = left;
            }
            else break;
        }
        else{ // (arr[left] < arr[right])
            if(arr[i]<arr[right]){
                swap(arr[i],arr[right]);
                i = right;
            }
            else break;
        }
    }
}

int main(){
    vector<int> arr = {10,2,14,11,1,4};
    int n = arr.size();
    print(arr);
    for(int i = n/2-1 ; i>=0 ; i--){
        heapify(i,arr,n);
    }
    print(arr);
}