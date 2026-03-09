/*
#   LeetCode-938 :- Range Sum of BST
    Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

    Example 1:
    Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
    Output: 32
    Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

    Example 2:
    Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
    Output: 23
    Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
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
int rangeSumBST(Node* root, int low, int high) {
    if(root == NULL) return 0;
    if(root->val <low) return rangeSumBST(root->right,low,high);
    else if(root->val > high) return rangeSumBST(root->left,low,high);
    else return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
}

int main(){
    vector<int> v = {10,5,15,3,7,INT_MIN,18};
    int low = 7 , high = 15;
    Node* root = construct(v);
    cout<<"Sum = "<<rangeSumBST(root,low,high);
}