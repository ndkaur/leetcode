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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<=1) return 0;
        int sell=0;
        int buy =-prices[0];
        int hold=0;
        for(int i=1;i<n;i++){
            int temp=sell;
            sell = max(sell,hold);
            hold= buy+prices[i];
            buy= max(buy,temp-prices[i]);
        }
        return max(sell,hold);
    }
};

// @lc code=end

// RECURSSION 
class Solution { // same as buy asd sell 2 
public:
    int f(int idx, int buy , vector<int>& prices){
        int n= prices.size();
        if(idx>=n) return 0;
        int profit=0;
        if(buy==1){
            profit =max(-prices[idx]+ f(idx+1, 0, prices), f(idx+1, 1, prices));
        }else{ // sell
            profit= max(prices[idx]+ f(idx+2,1, prices), f(idx+1, 0, prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return f(0,1, prices);
    }
};


//  MEMOIZATION 
class Solution { // same as buy asd sell 2 
public:
    int f(int idx, int buy , vector<int>& prices, vector<vector<int>>& dp){
        int n= prices.size();
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy==1){
            dp[idx][buy] =max(-prices[idx]+ f(idx+1, 0, prices,dp), f(idx+1, 1, prices,dp));
        }else{ // sell
           dp[idx][buy] = max(prices[idx]+ f(idx+2,1, prices,dp), f(idx+1, 0, prices,dp));
        }
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1, prices,dp);
    }
};

//  TABULATION 
class Solution { // same as buy asd sell 2 
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1)
                    dp[idx][buy] = max(-prices[idx]+dp[idx+1][0], dp[idx+1][1]);
                else 
                    dp[idx][buy] = max(prices[idx]+ dp[idx+2][1] , dp[idx+1][0]);
            }
        }
        return dp[0][1];
    }
};


class Solution { // same as buy asd sell 2 
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        
        for(int idx=n-1;idx>=0;idx--){

            dp[idx][1] = max(-prices[idx]+dp[idx+1][0], dp[idx+1][1]);
            
            dp[idx][0] = max(prices[idx]+ dp[idx+2][1] , dp[idx+1][0]);
            
        }
        return dp[0][1];
    }
};

class Solution { 
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> next1(2,0);
        vector<int> next2(2,0);
        vector<int> cur(2,0);
        
        for(int idx=n-1;idx>=0;idx--){
            
            cur[1] = max(-prices[idx]+next1[0], next1[1]);
            cur[0] = max(prices[idx]+ next2[1] , next1[0]);
            next2= next1;
            next1= cur;
        }
        return cur[1];
    }
};


int main(){
    Solution sol;
    vector<int> prices={1,2,3,0,2};
    int ans=sol.maxProfit(prices);
    cout<<ans;
    return 0;
}
