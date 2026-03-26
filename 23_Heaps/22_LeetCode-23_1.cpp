/*
#   LeetCode-23 :- Merge K sorted Lists
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    merging them into one sorted linked list:
    1->1->2->3->4->4->5->6

    Example 2:
    Input: lists = []
    Output: []

    Example 3:
    Input: lists = [[]]
    Output: []
!               Time Complexity :- O(nlog n)
!               Space Complexity :- O(n)
*/
#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto x : lists){
        while(x){
            pq.push(x->val);
            x = x->next;
        }
    }
    if(pq.size()==0){
        return NULL;
    }
    Node* result = new Node(pq.top());
    pq.pop();
    Node* current = result;
    while(pq.size()>0){
        current->next = new Node(pq.top());
        current = current->next;
        pq.pop();
    }
    return result;
}
// Helper: create linked list from vector
Node* createList(vector<int> arr){
    if(arr.size() == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
// Helper: print linked list
void printList(Node* head){
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main(){

    // Create K sorted lists
    vector<Node*> lists;

    lists.push_back(createList({1,4,5}));
    lists.push_back(createList({1,3,4}));
    lists.push_back(createList({2,6}));

    // Merge
    Node* mergedHead = mergeKLists(lists);

    // Print result
    printList(mergedHead);

    return 0;
}