/*
#   LeetCode-437 :- Path Sum III
    Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

    The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

    Example 1:
    Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    Output: 3
    Explanation: The paths that sum to 8 are shown.

    Example 2:
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    Output: 3  
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
Node* construct(vector<int>& v){
    int n = v.size();
    queue<Node*> q;
    Node* root = new Node(v[0]);
    q.push(root);
    int i = 1 , j = 2;
    while(q.size()>0 and i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(v[i]!=INT_MIN) l = new Node(v[i]);
        else l = NULL;
        if(j!=n and v[j]!=INT_MIN) r = new Node(v[j]);

        if(j!=n and v[j]!=INT_MIN) r = new Node(v[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2 , j+=2;
    }
    return root;
}
void helper(Node* root,long long sum , int& count){
    if(root == NULL) return;
    if((long long)(root->val)==sum) count++;
    helper(root->left,sum-(long long)(root->val),count);
    helper(root->right,sum-(long long)(root->val),count);
}
int pathSum(Node* root, int targetSum) {
    if(root == NULL) return 0;
    int count = 0;
    helper(root,(long long)(targetSum),count);
    count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
    return count;
}

int main(){
    vector<int> v = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1};
    int targetSum = 22;
    Node* root = construct(v);
    cout<<pathSum(root,targetSum);
}