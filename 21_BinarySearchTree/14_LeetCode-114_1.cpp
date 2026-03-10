/*
#   LeetCode-114 :- Flatten Binary Tree to Linked List
    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
    
    Example 1:
    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]

    Example 2:
    Input: root = []
    Output: []

    Example 3:
    Input: root = [0]
    Output: [0]
!                                           [Method-1]
                                    Time Complexity = O(n)
                                    Space Complexity = O(n)
*/
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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
vector<Node*> preorderTraversal(Node* root) {
    vector<Node*> ans;
    stack<Node*> st;
    if(root!=NULL) st.push(root);
    while(st.size()>0){
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp);
        if(temp->right!=NULL) st.push(temp->right);
        if(temp->left!=NULL) st.push(temp->left);
    }
    return ans;
}
void flatten(Node* root) {
    vector<Node*> ans = preorderTraversal(root);
    int n = ans.size();
    for(int i = 0 ; i<n-1 ; i++){
        ans[i]->right = ans[i+1];
        ans[i]->left = NULL;
    }
}

int main(){
    vector<int> v = {1,2,5,3,4,INT_MIN,6};
    Node* root = construct(v);
    flatten(root);
    levelOrder(root);
}