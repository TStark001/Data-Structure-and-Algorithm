/*
#   LeetCode-889 :- Construct Binary Tree from Preorder and Postorder Traversal
    Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

    If there exist multiple answers, you can return any of them.

    Example 1:
    Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
    Output: [1,2,3,4,5,6,7]

    Example 2:
    Input: preorder = [1], postorder = [1]
    Output: [1]
*/
#include<iostream>
#include<vector>
#include<queue>
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
        Node* l;
        Node* r;
        if(v[i]!=INT_MIN) l = new Node(v[i]);
        else l = NULL;
        if(j!=n and v[j]!=INT_MIN) r = new Node(v[j]);

        if(j!=n and v[j]!=INT_MIN) r = new Node(v[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2 , j+=2;
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
Node* build(vector<int>& pre , int prelo , int prehi , vector<int>& post , int postlo , int posthi){
    if(prelo>prehi) return NULL;
    Node* root = new Node(pre[prelo]);
    if(prelo == prehi) return root;
    int i = postlo;
    while(post[i]!=pre[prelo+1]) i++;
    int leftCount = i-postlo+1;
    root->left = build(pre,prelo+1,prelo+leftCount,post,postlo,i);
    root->right = build(pre,prelo+leftCount+1,prehi,post,i+1,posthi-1);
    return root;
}
Node* buildTree(vector<int>& pre, vector<int>& post){
    int n = post.size();
    return build(pre,0,n-1,post,0,n-1);
}

int main(){
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    Node* root = buildTree(preorder, postorder);
    levelOrder(root);
    return 0;
}