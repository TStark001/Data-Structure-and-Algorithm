/*
#   LeetCode-700 :- Search in a Binary Search Tree
    You are given the root of a binary search tree (BST) and an integer val.

    Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

    Example 1:
    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]

    Example 2:
    Input: root = [4,2,7,1,3], val = 5
    Output: []
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
        Node *l , *r;
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
void levelOrderQueue(Node* root){
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
Node* searchBST(Node* root , int val){
    if(root == NULL or root->val == val) return root;
    else if(root->val > val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}

int main(){
    vector<int> v = {4,2,7,1,3};
    int val = 2;
    Node* root = construct(v);
    Node* ans = searchBST(root,val);
    levelOrderQueue(ans);
}