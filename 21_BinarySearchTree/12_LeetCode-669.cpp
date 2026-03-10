/*
#   LeetCode-669 :- Trim a Binary Search Tree
    Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

    Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

    Example 1:
    Input: root = [1,0,2], low = 1, high = 2
    Output: [1,null,2]

    Example 2:
    Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
    Output: [3,2,null,1]
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
void trim(Node* root , int lo , int hi){
    if(root == NULL) return;
    while(root->left!=NULL){
        if(root->left->val < lo){
            root->left = root->left->right;
        }
        else if(root->left->val > hi){
            root->left = root->left->left;
        }
        else break;
    }
    while(root->right!=NULL){
        if(root->right->val > hi){
            root->right = root->right->left;
        }
        else if(root->right->val < lo){
            root->right = root->right->right;
        }
        else break;
    }
    trim(root->left,lo,hi);
    trim(root->right,lo,hi);
}
Node* trimBST(Node* root, int lo, int hi) {
    Node* dummy = new Node(INT_MAX);
    dummy->left = root;
    trim(dummy,lo,hi);
    return dummy->left;
}

int main(){
    vector<int> v = {3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1};
    int low = 1 , high = 3;
    Node* root = construct(v);
    Node* ans = trimBST(root,low,high);
    levelOrder(ans);
}