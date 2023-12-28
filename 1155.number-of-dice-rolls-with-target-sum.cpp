/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
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
    const int mod = 1e9+7;
    int f(int n, int k, int target,vector<vector<int>>& dp){
        if(n==0 && target==0)
            return 1;
        if(n==0 || target<=0)
            return 0;
        
        if(dp[n][target]!=-1)   
            return dp[n][target]%mod;
        
        int ways = 0;
        // k=2 faces, target =7, so target reduced for next dice 
        // f(1,k,6,dp) , f(1,k,4,dp) , f(1,k,1, dp), f(1, k, -3)
        // f(0,k,5,dp),  f(0,k,3,dp) , f(0,k,0,dp) ->valid dp[0][0] = 1
        for(int i=1; i<=k; i++){ 
            ways = (ways + f(n-1, k, target-i, dp))% mod;
        }

        dp[n][target] =  ways % mod;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        return f(n, k, target, dp);
    }
};

// @lc code=end


int main(){

    return 0;
}