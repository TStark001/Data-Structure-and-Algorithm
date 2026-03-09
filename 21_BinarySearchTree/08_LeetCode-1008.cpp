/*
#   LeetCode-1008 :- Construct Binary Search Tree from Preorder Traversal
    Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

    It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

    A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

    A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

    Example 1:
    Input: preorder = [8,5,1,7,10,12]
    Output: [8,5,10,1,7,null,12]

    Example 2:
    Input: preorder = [1,3]
    Output: [1,null,3]
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
//! to print null in output
void levelOrder(Node* root){
    queue<Node*> q;
    vector<string> ans;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp){
            ans.push_back(to_string(temp->val));
            q.push(temp->left);
            q.push(temp->right);
        }
        else{
            ans.push_back("null");
        }
    }
    // remove extra nulls from the end
    while(ans.size() > 0 && ans.back() == "null"){
        ans.pop_back();
    }
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i != ans.size()-1) cout<<",";
    }
    cout<<"]";
}
void insert(Node* root, int val) {
    if(root == NULL) root = new Node(val);
    else if(root->val > val){ // go left
        if(root->left == NULL){ // attach it here
            root->left = new Node(val);
        }
        else insert(root->left,val);
    }
    else{ // root->val < val : go right
        if(root->right == NULL){ // attach it here
            root->right = new Node(val);
        }
        else insert(root->right,val);
    }
}
Node* bstFromPreorder(vector<int>& preorder) {
    Node* root = new Node(preorder[0]);
    for(int i = 1 ; i<preorder.size() ; i++){
        insert(root,preorder[i]);
    }
    return root;
}

int main(){
    vector<int> v = {8,5,1,7,10,12};
    Node* root = bstFromPreorder(v);
    levelOrder(root);
}