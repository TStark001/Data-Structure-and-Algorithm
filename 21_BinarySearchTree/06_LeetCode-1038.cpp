/*
#   LeetCode-1038 :- Binary Search Tree to Greater Sum Tree
    Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

    As a reminder, a binary search tree is a tree that satisfies these constraints:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

    Example 1:
    Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

    Example 2:
    Input: root = [0,null,1]
    Output: [1,null,1]
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
void reverseInOrder(Node* root , int& sum){
    if(root == NULL) return;
    reverseInOrder(root->right , sum);
    root->val += sum;
    sum = root->val;
    reverseInOrder(root->left , sum);
}
Node* bstToGst(Node* root){
    int sum = 0;
    reverseInOrder(root,sum);
    return root;

}

int main(){
    vector<int> v = {4,1,6,0,2,5,7,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,8};
    Node* root = construct(v);
    Node* ans = bstToGst(root);
    levelOrder(ans);
}