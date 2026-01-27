/*
#   LeetCode-257 :- Binary Tree Paths
    Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.

    Example 1:
    Input: root = [1,2,3,null,5]
    Output: ["1->2->5","1->3"]

    Example 2:
    Input: root = [1]
    Output: ["1"]
*/
#include<iostream>
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
void helper(Node* root , string s , vector<string> &ans){
    if(root == NULL) return;
    string a = to_string(root->val);
    if(root->left == NULL and root->right == NULL){
        s += a;
        ans.push_back(s);
        return;
    }
    helper(root->left,s+a+"->",ans);
    helper(root->right,s+a+"->",ans);
}
vector<string> binaryTreePath(Node* root){
    vector<string> ans;
    helper(root,"",ans);
    return ans;
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(5);
    a->left = b;
    a->right = c;
    b->right = d;
    vector<string> result = binaryTreePath(a);
    for(string x : result){
        cout<<x<<"  ";
    }
}