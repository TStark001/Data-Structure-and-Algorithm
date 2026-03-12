/*
#    Binary Tree Left Side View
    Example 1:
    Input: root = [1,2,3,4,null,null,null,5]
    Output: [1,2,4,5]
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
Node* construct(vector<int>& arr){
    int n = arr.size();
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
void preOrder(Node* root,vector<int>& ans,int level){
    if(root == NULL) return;
    ans[level] = root->val;
    preOrder(root->right,ans,level+1);
    preOrder(root->left,ans,level+1);
}
vector<int> leftSideView(Node* root) {
    vector<int> ans(level(root),0);
    preOrder(root,ans,0);
    return ans;
}

int main(){
    vector<int> v = {1,2,3,4,INT_MIN,INT_MIN,INT_MIN,5};
    Node* root = construct(v);
    vector<int> result = leftSideView(root);
    for(int x : result){
        cout<<x<<" ";
    }
}