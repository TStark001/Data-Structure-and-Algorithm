/*
#   LeetCode-103 :- Binary Tree Zigzag Level Order Traversal
    Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]

    Example 2:
    Input: root = [1]
    Output: [[1]]

    Example 3:
    Input: root = []
    Output: []
!                               [Method-1]
                Time Complexity : O(n)
                Space Complexity : O(n)
*/
#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
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
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(q.size()>0){
        int size = q.size();
        vector<int> level;
        for(int i = 0 ; i<size ; i++){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        if(leftToRight == false) reverse(level.begin(),level.end());
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    return ans;
}

int main(){
    vector<int> v = {3,9,20,INT_MIN,INT_MIN,15,7};
    Node* root = construct(v);
    vector<vector<int>> result = zigzagLevelOrder(root);

    // print ans 
    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j];
            if(j != result[i].size()-1) cout << ",";
        }
        cout << "]";
        if(i != result.size()-1) cout << ",";
    }

    cout << "]";
}