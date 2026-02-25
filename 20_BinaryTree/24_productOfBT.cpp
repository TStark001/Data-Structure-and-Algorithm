/* 
    1.Product of all values in Binary Tree
    2.Minimum value of Binary Tree 
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
int level(Node* root){ // Levels of Tree
    if(root == NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
void nthLevel(Node* root,int curr,int level){
    if(root == NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return; 
    }
    nthLevel(root->left,curr+1,level); 
    nthLevel(root->right,curr+1,level); 
}
void levelOrder(Node* root){
    int n = level(root);
    for(int i = 1 ; i<=n ; i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}
int product(Node* root){
    if(root == NULL) return 1;
    return root->val * (product(root->left)*product(root->right));
}
int minValue(Node* root){
    if(root == NULL) return INT_MAX;
    int leftMin = minValue(root->left);
    int rightMin = minValue(root->right);
    return min(root->val,min(leftMin,rightMin));
}

int main(){
    vector<int> v = {1,2,3,4,5,INT_MIN,6};
    Node* root = construct(v);
    // levelOrder(root);
    cout<<"Product of Binary Tree = "<<product(root);
    cout<<endl<<"Minimum Value of Binary Tree = "<<minValue(root);
}