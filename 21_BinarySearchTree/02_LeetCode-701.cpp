/*
#   LeetCode-701 :- Insert Into a Binary Search Tree
    You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

    Example 1:
    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
    Explanation: Another accepted tree is:

    Example 2:
    Input: root = [40,20,60,10,30,50,70], val = 25
    Output: [40,20,60,10,30,50,70,null,null,25]

    Example 3:
    Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
    Output: [4,2,7,1,3,5]
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
Node* insertIntoBST(Node* root , int val){
    if(root == NULL) return new Node(val);
    else if(root->val > val){ // go left
        if(root->left == NULL){
            root->left = new Node(val);
        }
        else insertIntoBST(root->left,val);
    }
    else{ // go right
        if(root->right == NULL){
            root->right = new Node(val);
        }
        else insertIntoBST(root->right , val);
    }
    return root;
}

int main(){
    vector<int> v = {4,2,7,1,3};
    int val = 5;
    Node* root = construct(v);
    Node* ans = insertIntoBST(root,val);
    levelOrder(ans);
}