/*
#   LeetCode-230 :- Kth Smallest Element in a BST
    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

    Example 1:
    Input: root = [3,1,4,null,2], k = 1
    Output: 1

    Example 2:
    Input: root = [5,3,6,2,4,null,null,1], k = 3
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
void inOrder(Node* root,vector<int>& ans){
    if(root == NULL) return;
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}
int kthSmallest(Node* root, int k) {
    vector<int> ans;
    inOrder(root,ans);
    return ans[k-1];
}

int main(){
    vector<int> v = {7,3,10,1,5,INT_MIN,12};
    int k = 4;
    Node* root = construct(v);
    cout<<"Kth Element = "<<kthSmallest(root,k);
}