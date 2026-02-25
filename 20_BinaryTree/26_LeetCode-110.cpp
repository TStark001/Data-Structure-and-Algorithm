/*
#   LeetCode-110 :- Balanced Binary Tree
    Given a binary tree, determine if it is height-balanced.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: true

    Example 2:
    Input: root = [1,2,2,3,3,null,null,4,4]
    Output: false

    Example 3:
    Input: root = []
    Output: true
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
int checkHeight(Node* root){
    if(root == NULL) return 0;
    int leftHeight = checkHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight-rightHeight)>1) return -1;
    return 1+max(leftHeight,rightHeight);
}
bool isBalanced(Node* root) {
    if(checkHeight(root) == -1) return false;
    else return true;
}

int main(){
    vector<int> v = {3,9,20,INT_MIN,INT_MIN,15,7};
    Node* root = construct(v);
    if(isBalanced(root)==1) cout<<"True";
    else cout<<"False";
}