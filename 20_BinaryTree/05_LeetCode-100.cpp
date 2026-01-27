/*
#   LeetCode-100 :- Same Tree
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    Example 1:
    Input: p = [1,2,3], q = [1,2,3]
    Output: true

    Example 2:
    Input: p = [1,2], q = [1,null,2]
    Output: false

    Example 3:
    Input: p = [1,2,1], q = [1,1,2]
    Output: false
*/
#include<iostream>
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

bool isSameTree(Node* p , Node* q){
    if(p==NULL and q==NULL) return true;
    if(p==NULL or q==NULL) return false;
    if(p->val != q->val) return false;

    bool leftAns = isSameTree(p->left,q->left);
    if(leftAns == false) return false;

    bool rightAns =isSameTree(p->right,q->right);
    if(rightAns == false) return false;

    return true;
}

int main() {
    // Tree 1
    Node* t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);

    // Tree 2
    Node* t2 = new Node(1);
    t2->left = new Node(2);
    t2->right = new Node(3);

    if(isSameTree(t1, t2)) cout << "Trees are SAME" << endl;
    else cout << "Trees are NOT SAME" << endl;

    return 0;
}