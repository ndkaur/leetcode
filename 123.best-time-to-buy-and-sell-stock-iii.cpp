/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
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



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int buy1=INT_MAX;
        int buy2=INT_MAX;
        int sell1=0;
        int sell2=0;
        for(int i=0;i<n;i++){
            buy1= min(buy1,prices[i]);
            sell1 = max(sell1, prices[i]-buy1);
            buy2= min(buy2,prices[i]-sell1);
            sell2= max(sell2 , prices[i]-buy2);
        }
        return sell2;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int buy1=INT_MIN;
        int buy2=INT_MIN;
        int sell1=0;
        int sell2=0;
        for(int i:prices){
            sell2= max(sell2 , i+buy2);
            buy2= max(buy2,sell1-i);
            sell1 = max(sell1, i+buy1);
            buy1= max(buy1,-i);
        }
        return sell2;
    }
};
// @lc code=end

// RECURSION
class Solution {
public:
    int f(int idx, int buy , int trans , vector<int>& prices){
        int n= prices.size();
        if(idx==n) return 0;
        if(trans==0) return 0;
        int profit=0;
        if(buy){
            profit= max(-prices[idx]+ f(idx+1,0,trans,prices), f(idx+1,1, trans,prices));
        }else{
            profit= max(prices[idx]+ f(idx+1,1, trans-1,prices), f(idx+1,0, trans,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        return f(0,1,2,prices);
    }
};


// MEMOIZATION
class Solution {
public:
    int f(int idx, int buy , int trans , vector<int>& prices,vector<vector<vector<int>>>& dp){
        int n= prices.size();
        if(idx==n || trans==0) return 0;
        if(dp[idx][buy][trans]!=-1) return dp[idx][buy][trans];
        if(buy==1){
            return dp[idx][buy][trans] = max(-prices[idx]+ f(idx+1,0,trans,prices,dp), f(idx+1,1, trans,prices,dp));
        }
         return dp[idx][buy][trans] = max(prices[idx]+ f(idx+1,1, trans-1,prices,dp), f(idx+1,0, trans,prices,dp));
    
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};

// TABULATION  time O(n*2*3)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));
//         idx==n  then buy and trans will change 
//         for(int buy=0;buy<=1;buy++){
//             for(int trans=0;trans<=2;trans++){
//                 dp[n][buy][trans]=0;
//             }
//         }
// //         trans==0 then idx and buy will change 
//         for(int idx=0;idx<=n-1;idx++){
//             for(int buy=0;buy<=1;buy++){
//                 dp[idx][buy][0]= 0;
//             }
//         }
        
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=2;trans++){
                    if(buy==1){
                        dp[idx][buy][trans] = max(-prices[idx]+ dp[idx+1][0][trans], dp[idx+1][1][trans]);
                    } else {
                        dp[idx][buy][trans] = max(prices[idx]+ dp[idx+1][1][trans-1], dp[idx+1][0][trans]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};

// SPACE OPTIMIZATION
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> next(2, vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=1;trans<=2;trans++){
                    if(buy==1)
                        curr[buy][trans] = max(-prices[idx]+ next[0][trans], next[1][trans]);
                    else
                        curr[buy][trans] = max(prices[idx]+ next[1][trans-1], next[0][trans]);
                }
            }
            next= curr;
        }
        return next[1][2];
    }
};


class Solution {
public:
    int f(int idx, int trans, vector<int>& prices,vector<vector<int>>& dp){
        int n= prices.size();
        if(idx== n || trans==4) return 0;
        int profit = 0;
        if(dp[idx][trans]!=-1) return dp[idx][trans];
        if(trans%2==0){ // buy 
            profit= max(-prices[idx]+f(idx+1,trans+1,prices,dp), f(idx+1,trans,prices,dp));
        } else{ // sell
            profit= max(prices[idx]+ f(idx+1,trans+1,prices,dp), f(idx+1, trans, prices,dp));
        }
        return dp[idx][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return f(0,0,prices,dp);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5,0));
        for(int t=0;t<=4;t++){
            dp[n][t]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][4]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int t=3;t>=0;t--){
                if(t%2==0) // buy 
                    dp[i][t]= max(-prices[i]+dp[i+1][t+1], dp[i+1][t]);
                else // sell
                    dp[i][t]= max(prices[i]+ dp[i+1][t+1],dp[i+1][t]);  
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> next(5,0);
        vector<int> cur(5,0);

        for(int i=n-1;i>=0;i--){
            for(int t=0;t<4;t++){
                if(t%2==0) // buy 
                    cur[t]= max(-prices[i]+ next[t+1], next[t]);
                else // sell
                    cur[t]= max(prices[i]+ next[t+1],next[t]);  
            }
            next= cur;
        }
        return next[0];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // in the begining we want at idx = n-1 , i+1 so one extar idx that stores 0 
        vector<vector<int>>dp(n+1, vector<int>(5,0));
        for(int i=n-1; i>=0; i--){
            for(int j=3; j>=0; j--){
                if(j%2==0){
                    dp[i][j] = max(-prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution sol;
    vector<int> prices={3,3,5,0,0,3,1,4};
    int ans=sol.maxProfit(prices);
    cout<<ans;
    return 0;
}