/*
#   LeetCode-101 :- Symmetric Tree
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true

    Example 2:
    Input: root = [1,2,2,null,3,null,3]
    Output: false
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
        if(j<n and v[j]!=INT_MIN) r = new Node(v[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i += 2 , j += 2;
    }
    return root;
}
int level(Node* root){ // Levels of Tree
    if(root == NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void nthLevel(Node* root,int curr,int level){
    if(root == NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return; 
    }
    nthLevel(root->left,curr+1,level); 
    nthLevel(root->right,curr+1,level); 
}
void levelOrder(Node* root){
    int n = level(root);
    for(int i = 1 ; i<=n ; i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}
bool helper(Node* left,Node* right){
    if(left==NULL and right==NULL) return true;
    if(left==NULL or right==NULL) return false;
    if(left->val!=right->val) return false;
    return helper(left->left,right->right) and helper(left->right,right->left);
}
bool isSymmetric(Node* root){
    if(root == NULL) return true;
    return helper(root->left,root->right);
}

int main(){
    vector<int> v = {1,2,2,3,4,4,3};
    Node* root = construct(v);
    if(isSymmetric(root)==1) cout<<"True";
    else cout<<"False";
}