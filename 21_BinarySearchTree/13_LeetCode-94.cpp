/*
#   LeetCode-94 :- Binary Tree Inorder Traversal
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    Example 1:
    Input: root = [1,null,2,3]
    Output: [1,3,2]
    Explanation:

    Example 2:
    Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
    Output: [4,2,6,5,7,1,3,9,8]
    Explanation:

    Example 3:
    Input: root = []
    Output: []

    Example 4:
    Input: root = [1]
    Output: [1]
$                               Using Morrish Inorder Traversal
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
Node* construct(vector<int>& v){
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
vector<int> inorderTraversal(Node* root) {
    vector<int> ans;
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left!=NULL){ // find the pred
            Node* pred = curr->left;
            while(pred->right!=NULL and pred->right!=curr){
                pred = pred->right;
            }
            if(pred->right == NULL){ // Link
                pred->right = curr;
                curr = curr->left;
            }
            else{ // pred->right == curr : Unlink
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        else{ // curr->left == NULL
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,2,3,4,5,INT_MIN,8,INT_MIN,INT_MIN,6,7,9};
    Node* root = construct(v);
    vector<int> result = inorderTraversal(root);
    for(int x : result){
        cout<<x<<" ";
    }
}