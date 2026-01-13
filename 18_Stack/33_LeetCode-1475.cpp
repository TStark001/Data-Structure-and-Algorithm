/*
#   LeetCode-1475 :- Final Prices with a special Discount in a shop
    You are given an integer array prices where prices[i] is the price of the ith item in a shop.

    There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

    Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

    Example 1:
    Input: prices = [8,4,6,2,3]
    Output: [4,2,4,2,3]
    Explanation: 
    For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
    For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
    For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
    For items 3 and 4 you will not receive any discount at all.

    Example 2:
    Input: prices = [1,2,3,4,5]
    Output: [1,2,3,4,5]
    Explanation: In this case, for all items, you will not receive any discount at all.

    Example 3:
    Input: prices = [10,1,1,6]
    Output: [9,0,1,6]
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(n);
    stack<int> st;
    ans[n-1] = prices[n-1];
    st.push(prices[n-1]);
    for(int i = n-2 ; i>=0 ; i--){
        while(st.size()>0 and st.top()>prices[i]) st.pop();
        if(st.size() == 0){
            ans[i] = prices[i];
            st.push(prices[i]);
        } 
        else ans[i] = prices[i]-st.top();
        st.push(prices[i]);
    }
    return ans;
}
/*
$          CODE GIVEN BELOW IS MORE EFFICIENT
vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans = prices;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (st.size()!=0 && prices[st.top()] >= prices[i]) {
            ans[st.top()] -= prices[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
*/

int main(){
    vector<int> nums = {10,1,1,6};
    vector<int> result = finalPrices(nums);
    for(int x : result){
        cout<<x<<" ";
    }
}