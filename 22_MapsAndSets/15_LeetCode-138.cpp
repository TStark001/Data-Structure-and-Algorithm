/* 
#   LeetCode-138 :- Copy List with Random Pointer
    A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

    Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

    For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

    Return the head of the copied linked list.

    The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
    Your code will only be given the head of the original linked list.

    Example 1:
    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Example 2:
    Input: head = [[1,1],[2,1]]
    Output: [[1,1],[2,1]]

    Example 3:
    Input: head = [[3,null],[3,0],[3,null]]
    Output: [[3,null],[3,0],[3,null]]
    */
#include<iostream>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val){
        Node *temp = new Node(val);
        if (size == 0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void display(){
        Node *temp = head;
        while (temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
Node* copyRandomList(Node* head) {
    // step-1 :- create the deep copy without random pointer
    Node* dummy = new Node(-1);
    Node *tempC = dummy , *temp = head;
    while(temp){
        Node* a = new Node(temp->val);
        tempC->next = a;
        tempC = tempC->next;
        temp = temp->next;
    }
    Node* a = head;
    Node* b = dummy->next;
    // step-2 :- Make a map <original,duplicate>
    unordered_map<Node*,Node*> m;
    Node* tempA = a;
    Node* tempB = b;
    while(tempA!=NULL){
        m[tempA] = tempB;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    for(auto x : m){
        Node* o = x.first;
        Node* d = x.second;
        if(o->random!=NULL){ // kaam
            Node* oRandom = o->random;
            Node* dRandom = m[o->random];
            d->random = dRandom;
        }
    }
    return b;
}

int main(){
    // Step 1: Create nodes
    Node *n0 = new Node(7);
    Node *n1 = new Node(13);
    Node *n2 = new Node(11);
    Node *n3 = new Node(10);
    Node *n4 = new Node(1);

    // Step 2: Next pointers
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Step 3: Random pointers (based on input)
    n0->random = NULL; // [7, null]
    n1->random = n0;   // [13, 0]
    n2->random = n4;   // [11, 4]
    n3->random = n2;   // [10, 2]
    n4->random = n0;   // [1, 0]

    // Step 4: Copy the list
    Node *copiedHead = copyRandomList(n0);

    // Step 5: Print original list
    cout << "Original list (value -> random):\n";
    Node *temp = n0;
    while (temp){
        cout << temp->val << " -> ";
        if (temp->random)
            cout << temp->random->val;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }

    // Step 6: Print copied list
    cout << "\nCopied list (value -> random):\n";
    temp = copiedHead;
    while (temp){
        cout << temp->val << " -> ";
        if (temp->random) cout << temp->random->val;
        else cout << "NULL";
        cout << endl;
        temp = temp->next;
    }

    return 0;
}