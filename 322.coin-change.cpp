/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
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
    const int inf = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans= change(0,amount,coins,n);
        if(ans==inf)
            return -1;
        return ans;
    }
    int change(int pos,int amount, vector<int> &coins,int n){
        if(amount==0)
            return 0; 
        if(pos>=n || amount<0 )
            return inf;
        int left = 1+change(pos,amount-coins[pos],coins,n);
        int right = change(pos+1,amount,coins,n);
        return min(left,right);
    } /// time limit exceeded 
};

class Solution1 {
    const int inf=1e9;
    vector<vector<int>> dp;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp= vector<vector<int>>(n,vector<int>(amount+1,-1));
        int ans = change(0,amount,coins,dp);
        if(ans==inf)
            return -1;
        return ans;
    }
    int change(int pos,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(amount==0)
            return 0;
        if(pos>=coins.size() || amount<0)
            return inf;
        // pos and amount are changing parameters
        if(dp[pos][amount]!=-1)
            return dp[pos][amount];
        int left = 1+change(pos,amount-coins[pos],coins,dp);
        int right = change(pos+1,amount,coins,dp);
        return dp[pos][amount]=min(left,right);
    }
};


class Solution2 {
    const int inf=1e9;
    vector<vector<int>> dp;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp = vector<vector<int>>(n,vector<int>(amount+1,-1));
        int ans = change(0,amount,coins);
        if(ans==inf)
            return -1;
        return ans;
    }
    int change(int pos,int amount,vector<int>&coins){
        if(amount==0)
            return 0;
        if(pos>=coins.size() || amount<0)
            return inf;
        // pos and amount are changing parameters
        if(dp[pos][amount]!=-1)
            return dp[pos][amount];
        int left = 1+change(pos,amount-coins[pos],coins);
        int right = change(pos+1,amount,coins);
        return dp[pos][amount]=min(left,right);
    }
};


class Solution3 {
    const int inf=1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(amount+1,-1));
        int ans = change(0,amount,coins,dp);
        if(ans==inf)
            return -1;
        return ans;
    }
    int change(int pos,int amount,vector<int>&coins,vector<vector<int>> &dp){
        if(amount==0)
            return 0;
        if(pos>=coins.size() || amount<0)
            return inf;
        // pos and amount are changing parameters
        if(dp[pos][amount]!=-1)
            return dp[pos][amount];
        int left = 1+change(pos,amount-coins[pos],coins,dp);
        int right = change(pos+1,amount,coins,dp);
        return dp[pos][amount]=min(left,right);
    }
};

class Solution4 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp (amount+1,amount+1);
        dp[0]=0;
        for(auto coin:coins){
            for(int i=coin;i<=amount;i++){
                dp[i]=min(dp[i],1+dp[i-coin]);
            }
        }
        return dp[amount] >= amount+1 ? -1 : dp[amount];
    }
};


class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        long long t[n + 1][amount + 1];
        for (int i = 0;i<=n;i++)
            t[i][0] = 0;
        for (int j =1;j<=amount; j++)
            t[0][j] = INT_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j)
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }
        if (t[n][amount] == INT_MAX) return -1;
        return t[n][amount];
    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<int> coins ={1,2,5};
    int amount=11;
    int ans =sol.coinChange(coins,amount);
    cout<<ans;
    return 0;
}

// i-> 0 1 2 3 4 5 6 7 8 9 10 11   j= count  i = value
// 1   0 1 2 3 4 5 6 7 8 9 10 11
// 5   0 1 2 3 4 1 2 3 4 5  2  3    we will take either i-1 row or 
// 6   0 1 2 3 4 1 1 2 3 4  2  2     its  nth position back 
// 8   0 1 2 3 4 1 1 2 1 2  2  2 

// if(j>=cost[i])
//     dp[i][j]= min (dp[i-1][j], 1 + dp[i][j-cost[i]]);
// else 
//     dp[i][j]=dp[i-1][j];

