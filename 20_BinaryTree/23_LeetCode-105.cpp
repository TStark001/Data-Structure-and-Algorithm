/*
#   LeetCode-105 :- Construct Binary Tree from Preorder and Inorder
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/
#include<iostream>
#include<vector>
#include<queue>
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
    cout<<endl;
}
Node* build(vector<int>& pre,int prelo , int prehi , vector<int>& in , int inlo , int inhi){
    if(prelo>prehi) return NULL;
    Node* root = new Node(pre[prelo]);
    if(prelo == prehi) return root;
    int i = inlo;
    while(i<=inhi){
        if(in[i]==pre[prelo]) break;
        i++;
    }
    int leftCount = i - inlo;
    int rightCount = inhi - i;
    root->left = build(pre,prelo+1,prelo+leftCount,in,inlo,i-1);
    root->right = build(pre,prelo+leftCount+1,prehi,in,i+1,inhi);
    return root;
}
Node* buildTree(vector<int>& pre, vector<int>& in) {
    int n = pre.size();
    return build(pre,0,n-1,in,0,n-1);
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Node* root = buildTree(preorder, inorder);
    levelOrderQueue(root);
    return 0;
}