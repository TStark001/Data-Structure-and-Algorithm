/*
#   LeetCode-226 :- Invert Binary Tree
    Given the root of a binary tree, invert the tree, and return its root.

    Example 1:
    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]

    Example 2:
    Input: root = [2,1,3]
    Output: [2,3,1]

    Example 3:
    Input: root = []
    Output: []
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
Node* invertTree(Node* root){
    if(root == NULL) return NULL;
    /*
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp; 
    */
    swap(root->left , root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
void displayTree(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

int main(){
    Node* a = new Node(4);
    Node* b = new Node(2);
    Node* c = new Node(7);
    Node* d = new Node(1);
    Node* e = new Node(3);
    Node* f = new Node(6);
    Node* g = new Node(9);

    // Creating connection
   a->left = b;
   a->right = c;
   b->left = d;
   b->right = e;
   c->left = f;
   c->right = g;

    cout<<"Before invert: ";
    displayTree(a);

    invertTree(a);

    cout<<endl<<"After invert: ";
    displayTree(a);
}