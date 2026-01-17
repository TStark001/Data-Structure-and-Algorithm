#include<iostream>
#include<queue>
using namespace std;

void display(queue<int>& q){
    int n = q.size();
    for(int i = 1 ; i<= n ; i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    /* 
        push --> insertion happen at the back/rear ---> O(1)
        pop --> only happen at front ---> o(1)
        front -> top(we can access front of the queue ---> O(1))
        size --> return the size of the queue
        empty --> it returns true if size == 0 , else return false
        back --> we can only access the rear elements ---> O(1)
    
    %   Overflow --> #.only happen if we implement the queue via an array if you fill the array
    %                #.You are out of memory
    #   Underflow --> whenever the queue is empty and we try to use these functions - pop,front,back
    */
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
   /*  cout<<q.front()<<endl; // this will print the front element i.e. 10
    cout<<q.back()<<endl; // this will print the back element i.e. 50 */
    display(q);
    q.pop();
    /* cout<<q.front()<<endl; */
    display(q);
}