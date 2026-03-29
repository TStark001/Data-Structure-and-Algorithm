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
!           this is more optimize 
!           Time Complexity :- O(nlog K)
!           Space Complexity :- O(K)
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
typedef pair<int,Node*> p;
Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<p,vector<p>,greater<p>> pq;
    // Step 1 : push only first node of each list
    for(auto node : lists){
        if(node!=NULL){
            pq.push({node->val,node});
        }
    }
    // Step 2 : creating dummy and temp node
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(pq.size()>0){
        // pair<int, Node*> temp == auto temp
        auto x = pq.top();
        pq.pop();
        Node* node = x.second;
        temp->next = node;
        temp = node;
        // push next node of same list
        if(node->next!=NULL){
            pq.push({node->next->val,node->next});
        }
    }
    return dummy->next;
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