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
void reverseInorder(Node* root , vector<int>& arr){
    if(root == NULL) return;
    reverseInorder(root->right,arr);
    arr.push_back(root->val);
    reverseInorder(root->left,arr);
}
void preorder(Node* root , vector<int>& arr , int& idx){
    if(root == NULL) return;
    root->val = arr[idx++];
    preorder(root->left,arr,idx);
    preorder(root->right,arr,idx);
}
void print(vector<int> arr){
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v = {10,5,16,1,8,12,20};
    Node* root = construct(v);
    cout<<"BST befor Maxheap :- "<<endl;
    levelOrder(root);
    vector<int> arr;
    reverseInorder(root,arr);
    cout<<endl<<"ReverseInorder Traversal :- "<<endl;
    print(arr);
    int idx = 0;
    preorder(root,arr,idx); // BST -> MaxHeap
    cout<<endl<<"MaxHeap Tree :- "<<endl;
    levelOrder(root);
}