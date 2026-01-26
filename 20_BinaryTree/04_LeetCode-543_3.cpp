/*
#   LeetCode-543 :- Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [1,2,3,4,5]
            1
           / \
          2   3
         / \
        4   5
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1
!                           Using Global Variable
*/
#include<iostream>
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
int maxDia=0;
int check(Node* root){
    if(root==NULL) return 0;
    int left= check(root->left);
    int right=check(root->right);
    if(left+right>maxDia) maxDia = left+right;
    return max(left,right)+1;
}
int diameterOfBinaryTree(Node* root) {
    check(root);
    return maxDia;
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    cout<<"Diameter of Tree = "<<diameterOfBinaryTree(a);
}