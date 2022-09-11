/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        if(n<2) return 0;
        if(k>n/2){
            int ans=0;
            for(int i=1;i<n;i++)
                ans+= max(prices[i]-prices[i-1],0);
            return ans;
        }
        int hold[k+1];
        int sell[k+1];
        for(int i=0;i<=k;i++){
            hold[i]=INT_MIN;
            sell[i]=0;
        }
        int curr;
        for(int i=0;i<n;i++){
            for(int j=k;j>0;j--){
                sell[j]=max(sell[j],hold[j]+prices[i]);
                hold[j]=max(hold[j],sell[j-1]-prices[i]);
            }
        }
        return sell[k];
    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        if(k>n/2){
            int ans=0;
            for(int i=1;i<n;i++)
                ans+= max(prices[i]-prices[i-1],0);
            return ans;
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(prices, 0,0,1,k,dp);
    }
    int find(vector<int>& prices, int i,int trans,bool buy,int k, vector<vector<vector<int>>>& dp){
        int n= prices.size();
        if(i>=n || trans>=k) return 0;
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        if(buy)
            return dp[i][buy][trans]= max(-prices[i]+find(prices,i+1,trans,!buy,k,dp), find(prices,i+1,trans,buy,k,dp));
        else
            return dp[i][buy][trans] = max(prices[i]+ find(prices,i+1,trans+1,!buy,k,dp),find(prices,i+1,trans,buy,k,dp));
    }
};

// @lc code=end
 
// RECURSSION 
class Solution {
public:
    int f(int idx, int trans, int k, vector<int>& prices){
        int n= prices.size();
        if(idx==n || trans==2*k) // 1 trans = 2 steps 
            return 0;
        if(trans%2==0){
            return max(-prices[idx]+ f(idx+1, trans+1,k, prices), f(idx+1, trans, k, prices));
        }
        return max(prices[idx]+ f(idx+1, trans+1, k,prices), f(idx+1, trans, k, prices));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        return f(0,0,k,prices);
    }
};


// MEMOIZATION
class Solution {
public:
    int f(int idx, int trans, int k, vector<int>& prices, vector<vector<int>>& dp){
        int n= prices.size();
        if(idx==n || trans==2*k) // 1 trans = 2 steps 
            return 0;
        if(dp[idx][trans]!=-1) return dp[idx][trans];
        // b s b s
        // 0 1 2 3  even idx =buy
        if(trans%2==0){
            return dp[idx][trans]=max(-prices[idx]+ f(idx+1, trans+1,k, prices,dp), f(idx+1, trans, k, prices,dp));
        }
        return dp[idx][trans]= max(prices[idx]+ f(idx+1, trans+1, k,prices,dp), f(idx+1, trans, k, prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp (n, vector<int>(2*k,-1));
        return f(0,0,k,prices,dp);
    }
};

//  tabulation 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp (n+1, vector<int>(2*k+1,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){
                    dp[idx][trans] = max(-prices[idx]+dp[idx+1][trans+1], dp[idx+1][trans]);
                }
                else 
                    dp[idx][trans] = max(prices[idx]+ dp[idx+1][trans+1], dp[idx+1][trans]);
                
            }
        }
        return dp[0][0];
    }
};

//  space optimization 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<int> next(2*k+1 ,0);
        vector<int> cur(2*k+1, 0);
        
        for(int idx=n-1;idx>=0;idx--){
            for(int trans=2*k-1;trans>=0;trans--){
                if(trans%2==0){
                    cur[trans] = max(-prices[idx]+next[trans+1], next[trans]);
                }
                else 
                    cur[trans] = max(prices[idx]+ next[trans+1], next[trans]);
                
            }
            next= cur;
        }
        return next[0];
    }
};

int main(){
    Solution sol;
    vector<int> prices={3,2,6,0,5,3};
    int k =2;
    int ans=sol.maxProfit(k,prices);
    cout<<ans;
    return 0;
}

// tle with 3d dp  //time -> O(n*2*k)   space ->O(n*2*k) + O(n)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return f(0,0,k, prices, dp);
    }
    int f(int idx, int buy , int k , vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n= prices.size();
        if(k==0 || idx==n) 
            return 0;
        int ans ;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        if(buy==0){ // can buy 
            ans =  max(-prices[idx] + f(idx+1,1,k, prices,dp) , f(idx+1,0,k, prices,dp));
        }
        if(buy == 1){ // can sell
            ans= max(prices[idx] + f(idx+1, 0, k-1, prices, dp) , f(idx+1, 1, k, prices, dp));
        }
        
        return ans;
    }
};

// tabulation with 3d dp // time = space = O( n*2*k) 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap= 1; cap<=k; cap++){
                    if(buy==0)
                        dp[i][buy][cap] = max(-prices[i]+ dp[i+1][1][cap] , dp[i+1][0][cap]);
                    if(buy==1)
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][0][cap-1] , dp[i+1][1][cap]);
                }
            }
        }
        
        return dp[0][0][k];
    }
};