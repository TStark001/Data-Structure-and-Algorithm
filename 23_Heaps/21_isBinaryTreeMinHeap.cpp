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
int sizeOfTree(Node* root){
    if(root == NULL) return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}
bool isMinHeap(Node* root){
    if(root == NULL) return true;
    if(root->left!=NULL and root->val > root->left->val) return false;
    if(root->right!=NULL and root->val > root->right->val) return false;
    return isMinHeap(root->left) and  isMinHeap(root->right);
}
bool isCBT(Node* root){
    int size = sizeOfTree(root);
    int count = 0;
    queue<Node*> q;
    q.push(root);
    while(count<size){
        Node* temp = q.front();
        q.pop();
        count++;
        if(temp!=NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    if(q.size()>0){
        Node* temp = q.front();
        if(temp!=NULL) return false;
        q.pop();
    }
    return true;
}

int main(){
    vector<int> v1 = {6, 8, 10, 20, 11,INT_MIN, 15};
    Node* root1 = construct(v1);
    if(isCBT(root1) and isMinHeap(root1)) cout<<"Tree is MinHeap.";
    else cout<<"Tree is not a MinHeap!";
    cout<<endl;
    
    vector<int> v2 = {6, 8, 10, 20, 11, 15};
    Node* root2 = construct(v2);
    if(isCBT(root2) and isMinHeap(root2)) cout<<"Tree is MinHeap.";
    else cout<<"Tree is not a MinHeap!";
}