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

// 1 dp 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1 ,-1);
        int cnt = f(coins, amount,dp);
        if(cnt == INT_MAX)
            return -1;
        else 
            return cnt;
    }
    int f(vector<int>& coins, int amount, vector<int>& dp){
        int  n = coins.size();
        if(amount == 0)
            return 0;
        if(amount<0)
            return INT_MAX;
        
        if(dp[amount]!=-1)
            return dp[amount];

        int mn =INT_MAX;
        for(int i=0; i<n; i++){
            int pick = f(coins, amount-coins[i], dp);
            if(pick != INT_MAX){
                mn = min(mn, pick+1);
            }
        }
        dp[amount] = mn;
        return dp[amount];
    }
};

// number of ways to find 
class Solution0 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        int ans= f(n-1, amount, coins);
        if(ans == 1e9)
            return -1;
        return ans;
    }
    int f(int idx, int amount, vector<int>& coins){
        if(idx==0){ // exactly divisble then just count how many coins make the amount 
            if(amount % coins[idx] ==0){
                return amount / coins[idx];
            }
            else 
                return 1e9;
        }
        int ntake= f(idx -1, amount, coins);
        int take = 1e9;
        if(coins[idx] <= amount){
            take =  1+ f(idx, amount-coins[idx], coins);
        }
        return min(take, ntake);
        
    }
};


class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans= f(n-1, amount, coins,dp);
        if(ans == 1e9)
            return -1;
        return ans;
    }
    int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(idx==0){
            if(amount % coins[idx] ==0){
                return amount / coins[idx];
            }
            else 
                return 1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int ntake= f(idx -1, amount, coins, dp);
        int take = 1e9;
        if(coins[idx] <= amount){
            take =  1+ f(idx, amount-coins[idx], coins,dp);
        }
        return dp[idx][amount] = min(take, ntake);
        
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for(int target=0; target<=amount; target++){
            if(target % coins[0] ==0 )
                dp[0][target] = target/ coins[0];
            else
                dp[0][target] = 1e9;
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int ntake= dp[i-1][j];
                int take = 1e9;
                if(coins[i] <= j){
                     take =  1+ dp[i][j-coins[i]];
                }
                dp[i][j] = min(take, ntake);
            }
        }
        
        int ans= dp[n-1][amount];
        if(ans == 1e9)
            return -1;
        return ans;
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


// [1,2,5]
// 11
// target ->
//  1   0 1 2 3 4 5 6 7 8 9 10 11 
//  2   0 1 1 2 2 3 3 4 4 5 5   6 
//  5   0 1 1 2 2 1 2 2 3 3 2   3 
