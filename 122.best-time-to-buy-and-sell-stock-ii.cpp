/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
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
        int n =prices.size();
        int i=0;
        int peak= prices[0];
        int low = prices[0];
        int mx=0;

        while(i<n-1){
            while(i<n-1 && prices[i]>=prices[i+1]) 
                i++;
            low =prices[i];
            while(i<n-1 && prices[i]<=prices[i+1])
                i++;
            peak=prices[i];
            mx=mx+peak-low;
        }
        return mx;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int mx=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
                mx+= prices[i]-prices[i-1];
        }
        return mx;
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<2) return 0;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return find(prices,0,1,dp);
    }
    int find(vector<int>& prices, int i, bool buy, vector<vector<int>>&dp){
        int n = prices.size();
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
            return dp[i][buy] = max(-prices[i]+find(prices,i+1,!buy,dp),find(prices,i+1,buy,dp));
        else 
            return dp[i][buy] = max(prices[i]+find(prices,i+1,!buy,dp),find(prices,i+1,buy,dp));      
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> buy(n);
        vector<int> sell(n);
        sell[0] =0;
        buy[0]= -prices[0];
        for(int i=1;i<n;i++){
            sell[i] = max(sell[i-1],prices[i]+ buy[i-1]);
            buy[i] = max(buy[i-1],sell[i-1]-prices[i]);
        }     
        return max(sell[n-1],buy[n-1]);
    }
};
// @lc code=end

// RECURSION -> TIME = 2^N    SPACE -> o(N)

class Solution {
public:
    int f(int idx, bool buy, vector<int>& prices){
        int n= prices.size();
        if(idx==n) return 0;
        int profit=0;
        if(buy){
            profit= max(-prices[idx]+f(idx+1,0,prices) , f(idx+1,1,prices));
        }else{ // sell
            profit= max(prices[idx]+f(idx+1,1,prices),f(idx+1,0,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        return f(0,1,prices);
    }
};

// MEMOIZATION -> time  O(n*2)    space =O(n*2) +O(n) // auxilary stack space

class Solution {
public:
    int f(int idx, bool buy, vector<int>& prices,vector<vector<int>>& dp){
        int n= prices.size();
        if(idx==n) return 0; // buy =1, sell =0
        int profit=0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            profit= max(-prices[idx]+f(idx+1,0,prices,dp) , f(idx+1,1,prices,dp));
        }else{ // sell
            profit= max(prices[idx]+f(idx+1,1,prices,dp),f(idx+1,0,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};

// TABULATION  space O(n*2)   time O(n*2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n][0] = dp[n][1]=0;
        int profit=0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy){           // buy                       // not buy
                    profit= max(-prices[idx]+dp[idx+1][0] , dp[idx+1][1]);
                }else{ // sell
                    profit= max(prices[idx]+dp[idx+1][1],dp[idx+1][0]);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};

// SPACE OPTIMIZATION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> next(2,0);
        vector<int> curr(2,0);
        next[0] = next[1]=0;
        int profit=0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy){           // buy                       // not buy
                    profit= max(-prices[idx]+next[0] , next[1]);
                }else{ // sell
                    profit= max(prices[idx]+next[1],next[0]);
                }
                curr[buy]=profit;
            }
            next= curr;
        }
        return next[1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int nextNotBuy , nextbuy, curBuy , curNotBuy;
        nextNotBuy = nextbuy =0;
        
        for(int idx=n-1;idx>=0;idx--){
            //  sell
            curNotBuy = max(prices[idx]+nextbuy , nextNotbuy);
            curBuy = max(-profit[idx]+ nextNotBuy , nextbuy);
            nextbuy = curBuy;
            nextNotBuy = curNotBuy;
            
        }
        return nextbuy;
    }
};

int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    int m =sol.maxProfit(prices);
    cout<<m;
    return 0;
}