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
Node* min(Node* root){
    if(root == NULL) return NULL;
    Node* minNode = root;
    while(minNode->left!=NULL){
        minNode = minNode->left;
    }
    return minNode;
}
Node* max(Node* root){
    if(root == NULL) return NULL;
    Node* maxNode = root;
    while(maxNode->right!=NULL){
        maxNode = maxNode->right;
    }
    return maxNode;
}

int main(){
    vector<int> v = {8,3,10,1,6,INT_MIN,14};

    Node* root = construct(v);

    Node* minNode = min(root);
    Node* maxNode = max(root);

    cout << "Minimum value: " << minNode->val << endl;
    cout << "Maximum value: " << maxNode->val << endl;
}
