/*
#   LeetCode-108 :- Convert Sorted Array to Binary Search Tree
    Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

    Example 1:
    Input: nums = [-10,-3,0,5,9]
    Output: [0,-3,9,-10,null,5]
    Explanation: [0,-10,5,null,-3,null,9] is also accepted:

    Example 2:
    Input: nums = [1,3]
    Output: [3,1]
    Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
*/
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* construct(vector<int> v){
    int n = v.size();
    queue<Node*> q;
    Node* root = new Node(v[0]);
    q.push(root);
    int i = 1 , j = 2;
    while(q.size()>0 and i<n){
        Node* temp = q.front();
        q.pop();
        Node *l, *r;

        if(v[i]!=INT_MIN) l = new Node(v[i]);
        else l = NULL;
        if(j!=n and v[j]!=INT_MIN) r = new Node(v[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i += 2 , j += 2;
    }
    return root;
}
/*
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}
*/
//! to print null in output
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<"null ";
            continue;
        }

        cout<<temp->val<<" ";

        q.push(temp->left);   // push even if NULL
        q.push(temp->right);  // push even if NULL
    }
}
Node* helper(vector<int>& arr,int lo,int hi){
    if(lo>hi) return NULL;
    int mid = lo + (hi-lo)/2;
    Node* root = new Node(arr[mid]);
    root->left = helper(arr,lo,mid-1);
    root->right = helper(arr,mid+1,hi);
    return root;
}
Node* sortedArrayToBST(vector<int>& arr) {
    int n = arr.size();
    return helper(arr,0,n-1);
}

int main(){
    vector<int> v = {-10,-3,0,5,9};
    Node* root = sortedArrayToBST(v);
    levelOrder(root);
}