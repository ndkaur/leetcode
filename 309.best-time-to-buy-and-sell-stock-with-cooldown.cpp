/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
// @lc code=start
class Solution0 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int A=0;
        int B= -prices[0];
        int C =0;
        for(int i=1;i<prices.size();i++){
            int temp =A;
            A= max(A,C);
            C= B+prices[i];
            B= max(B,temp-prices[i]);
        }
        return max(A,C);
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<=1) return 0;
        vector<int> buy(n,0);
        vector<int> hold(n,0);
        vector<int> sell(n,0);
        buy[0]=-prices[0];
        sell[0]= INT_MIN;
        for(int i=1;i<n;i++){
            // buy -> money ->profit-price today 
            buy[i]=max(buy[i-1],hold[i-1]-prices[i]);
            // hold -> 1. do nothing , 2. hold when sold yesterday 
            hold[i]= max(hold[i-1],sell[i-1]);
            // sell -> 1. do nothing use previous  2.sell it= buy +today price 
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
        }
        return max(hold[n-1],sell[n-1]);
    }
};


class Solution {
    const int inf = 1e9;
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<=1) return 0;
        vector<int>buy(n+1,-inf);
        vector<int> sell(n+1);
        for(int i=1;i<=n;i++){
            // buy -> 1. do nothing , 2. buy if first buy or buy after cooldown 
            // buy sell(i-2) cooldown(i-1) buy(i) sell 
            buy[i]= max(buy[i-1],(i-2>=0 ? sell[i-2]:0)-prices[i-1]);
            sell[i] = max(sell[i-1],buy[i-1]+prices[i-1]);
        }
        return sell[n];
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> prices={1,2,3,0,2};
    int ans=sol.maxProfit(prices);
    cout<<ans;
    return 0;
}
