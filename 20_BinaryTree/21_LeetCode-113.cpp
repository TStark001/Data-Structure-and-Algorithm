/*
#   LeetCode-113 :- Path Sum II
    Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

    A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

    Example 1:
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    Output: [[5,4,11,2],[5,8,4,5]]
    Explanation: There are two paths whose sum equals targetSum:
    5 + 4 + 11 + 2 = 22
    5 + 8 + 4 + 5 = 22

    Example 2:
    Input: root = [1,2,3], targetSum = 5
    Output: []

    Example 3:
    Input: root = [1,2], targetSum = 0
    Output: []
*/
#include<iostream>
#include<queue>
#include<climits>
#include<vector>
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
void helper(Node* root,vector<int> v,vector<vector<int>>& ans,int sum){
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL){
        if(root->val==sum){
            v.push_back(root->val);
            ans.push_back(v);
        }
        return;
    }
    v.push_back(root->val);
    helper(root->left,v,ans,sum-(root->val));
    helper(root->right,v,ans,sum-(root->val));
}
vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> v;
    helper(root,v,ans,targetSum);
    return ans;
}

int main(){
    vector<int> v = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1};
    int targetSum = 22;
    Node* root = construct(v);
    vector<vector<int>> result = pathSum(root,targetSum);
    for(auto row : result){
        for(auto val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}