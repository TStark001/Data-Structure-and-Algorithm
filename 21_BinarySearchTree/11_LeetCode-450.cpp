/*
#   LeetCode-450 :- Delete Node in a BST
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

    Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.

    Example 1:
    Input: root = [5,3,6,2,4,null,7], key = 3
    Output: [5,4,6,2,null,null,7]
    Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
    One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
    Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

    Example 2:
    Input: root = [5,3,6,2,4,null,7], key = 0
    Output: [5,3,6,2,4,null,7]
    Explanation: The tree does not contain a node with value = 0.

    Example 3:
    Input: root = [], key = 0
    Output: []
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
Node* iop(Node* root){
    Node* pred = root->left;
    while(pred->right!=NULL){
        pred = pred->right;
    }
    return pred;
}
Node* deleteNode(Node* root , int key){
    if(root == NULL) return NULL;
    if(root->val == key){
        // Case 1 :No Child
        if(root->left == NULL and root->right == NULL) return NULL;

        // Case 2 : 1 Child node
        if(root->left == NULL or root->right == NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
        }

        // Case 3 : 2 Child node
        if(root->left!=NULL and root->right!=NULL){
            // replace the root with its inorder pred/succ
            // after replacing delete the pred/succ
            Node* pred = iop(root);
            root->val = pred->val;
            root->left = deleteNode(root->left,pred->val);
        }
    }
    else if(root->val > key){ // go left
        root->left = deleteNode(root->left,key);
    }
    else{ // go right
        root->right = deleteNode(root->right,key);
    }
    return root;
}

int main(){
    vector<int> v = {5,3,6,2,4,INT_MIN,7};
    int key = 3;
    Node* root = construct(v);
    Node* ans = deleteNode(root,key);
    levelOrder(ans);
}