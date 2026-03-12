/*
#   LeetCode-1382 :- Balance a Binary Search Tree
    Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

    Example 1:
    Input: root = [1,null,2,null,3,null,4,null,null]
    Output: [2,1,3,null,null,null,4]
    Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

    Example 2:
    Input: root = [2,1,3]
    Output: [2,1,3]
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
void inorder(Node* root , vector<int>& v){
    if(root == NULL) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
Node* build(vector<int>& v , int l , int r){
    if(l>r) return NULL;
    int mid = (l+r)/2;
    Node* root = new Node(v[mid]);
    root->left = build(v,l,mid-1);
    root->right = build(v,mid+1,r);
    return root;
}
Node* balanceBST(Node* root){
    vector<int> v;
    inorder(root,v);
    return build(v,0,v.size()-1);
}

int main(){
    vector<int> v = {1,INT_MIN,2,INT_MIN,3,INT_MIN,4,INT_MIN,INT_MIN};
    Node* root = construct(v);
    Node* ans = balanceBST(root);
    levelOrder(ans);
}