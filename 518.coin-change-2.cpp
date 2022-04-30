/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int f(vector<int>& coins , int idx, int amount){
        if(idx==0){
             return (amount % coins[0]==0);
        }
     
        int notPick= f(coins,idx-1, amount);
        int pick = 0;
        if(coins[idx]<= amount)
            pick= f(coins,idx, amount-coins[idx]);
        
        return pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
         int n= coins.size();
        return f(coins,n-1, amount);
    }
};


class Solution1 {
public:
    int f(vector<int>& coins , int idx, int amount,vector<vector<int>>& dp){
        if(idx==0){
             return (amount % coins[0]==0);
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notPick= f(coins,idx-1, amount,dp);
        int pick = 0;
        if(coins[idx]<= amount)
            pick= f(coins,idx, amount-coins[idx],dp);
        
        return dp[idx][amount]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        
         int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return f(coins,n-1, amount,dp);
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        for(int t=0 ;t<=amount;t++){
            dp[0][t]= (t%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int t= 0;t<= amount ;t++){
                int notPick= dp[i-1][t];
                int pick=0;
                if(coins[i]<=t)
                    pick = dp[i][t-coins[i]];
                dp[i][t]= pick+notPick;
            }
        }
        return dp[n-1][amount];
    }
};
// @lc code=end


int main(){

    return 0;
}