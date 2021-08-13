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


int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    int m =sol.maxProfit(prices);
    cout<<m;
    return 0;
}