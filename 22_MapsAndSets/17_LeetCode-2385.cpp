/*
#   LeetCode-2385 :- Amount of Time for Binary Tree to Be Infected
    You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
    Each minute, a node becomes infected if:
    The node is currently uninfected.
    The node is adjacent to an infected node.
    Return the number of minutes needed for the entire tree to be infected.

    Example 1:
    Input: root = [1,5,3,null,4,10,6,9,2], start = 3
    Output: 4
    Explanation: The following nodes are infected during:
    - Minute 0: Node 3
    - Minute 1: Nodes 1, 10 and 6
    - Minute 2: Node 5
    - Minute 3: Node 4
    - Minute 4: Nodes 9 and 2
    It takes 4 minutes for the whole tree to be infected so we return 4.

    Example 2:
    Input: root = [1], start = 1
    Output: 0
    Explanation: At minute 0, the only node in the tree is infected so we return 0.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
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
Node* first = NULL;
void markParent(Node* root,unordered_map<Node*,Node*>& parent){
    if(root == NULL) return;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    markParent(root->left,parent);
    markParent(root->right,parent);
}
void find(Node* root , int start){
    if(root == NULL) return;
    if(root->val == start){
        first = root;
        return;
    }
    find(root->left,start);
    find(root->right,start);
}
int amountOfTime(Node* root, int start) {
    find(root,start);
    unordered_map<Node*,Node*> parent;
    markParent(root,parent);
    unordered_set<Node*> s; // is Infected
    s.insert(first);
    queue<pair<Node*,int>> q;
    q.push({first,0});
    int maxLevel = 0;
    // BFS
    while(q.size()>0){
    pair<Node*,int> p = q.front();
    q.pop();
    Node* temp = p.first;
    int level = p.second;
    maxLevel = max(maxLevel,level);
    if(temp->left){
            if(s.find(temp->left)==s.end()){
                q.push({temp->left,level+1});
                s.insert(temp->left);
            }
        }
        if(temp->right){
            if(s.find(temp->right)==s.end()){
                q.push({temp->right,level+1});
                s.insert(temp->right);
            }
        }
        if(parent.find(temp)!=parent.end()){
            if(s.find(parent[temp])==s.end()){
                q.push({parent[temp],level+1});
                s.insert(parent[temp]);
            }
        }
    }
    return maxLevel;    
}

int main(){
    vector<int> v = {1,5,3,INT_MIN,4,10,6,9,2};
    int start = 3;
    Node* root = construct(v);
    cout<<"Amount of Time to be Infected = "<<amountOfTime(root,start)<<" minutes";
}