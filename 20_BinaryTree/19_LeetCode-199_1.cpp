/*
#   LeetCode-199 :- Binary Tree Right Side View
    Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

    Example 1:
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
    Explanation:

    Example 2:
    Input: root = [1,2,3,4,null,null,null,5]
    Output: [1,3,4,5]
    Explanation:

    Example 3:
    Input: root = [1,null,3]
    Output: [1,3]

    Example 4:
    Input: root = []
    Output: []
*/
#include<iostream>
#include<queue>
#include<climits>
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
Node* construct(int arr[] , int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1 , j = 2;
    while(q.size()>0 and i<n){
        Node* temp = q.front();
        q.pop();
        Node *l , *r;
        if(arr[i]!=INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j!=n and arr[j]!=INT_MIN) r = new Node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i += 2 , j += 2;
    }
    return root;
}
int level(Node* root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void nthLevel(Node* root,int curr,int level,vector<int>& ans){
    if(root==NULL) return;
    if(curr==level){
        ans[curr] = root->val;
        return;
    }
    nthLevel(root->left,curr+1,level,ans);
    nthLevel(root->right,curr+1,level,ans);
}
void levelOrder(Node* root,vector<int>& ans){
    int n = ans.size();
    for(int i = 0 ; i<n ; i++){
        nthLevel(root,0,i,ans);
    }
}
vector<int> rightSideView(Node* root) {
    vector<int> ans(level(root),0);
    levelOrder(root,ans);
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,INT_MIN,INT_MIN,INT_MIN,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    vector<int> result = rightSideView(root);
    for(int x : result){
        cout<<x<<" ";
    }
}