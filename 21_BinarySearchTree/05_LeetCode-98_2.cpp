/*
#   LeetCode-98 :- Validate Binary Search Tree
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys strictly less than the node's key.
    The right subtree of a node contains only nodes with keys strictly greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    

    Example 1:
    Input: root = [2,1,3]
    Output: true

    Example 2:
    Input: root = [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.
!                               [METHOD-2(using InOrder Traversal)]
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
void inOrder(Node* root , vector<int> &ans){
    if(root == NULL) return;
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}
bool isValidBST(Node* root) {
    vector<int> ans;
    inOrder(root,ans);
    for(int i = 1 ; i<ans.size() ; i++){
        if(ans[i] <= ans[i-1]) return false;
    }
    return true;
}

/*
$    Time Complexity :- O(n)
$    Space Complexity :- O(n)
*/

int main(){
    vector<int> v = {5,1,4,INT_MIN,INT_MIN,3,6};
    Node* root = construct(v);
    if(isValidBST(root) == 1) cout<<"True";
    else cout<<"False";
}