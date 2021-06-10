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

class Solution0 {
public:
    int coinChange(vector<int>& coins, int n, int amount){
        if(n==0)
            return 0;
        if(amount == 0)
            return 1;
        if(coins[n-1] > amount)
            return coinChange(coins, n-1, amount);
        return coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0)
            return 1;
        if(n==0)
            return 0;
        return coinChange(coins, n, amount);
    }
};


class Solution1 {
public:
    int change(int sum,vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        dp[0][0]=1;

        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(coins[i-1]<=j)
                    dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
        return dp[n][sum];
    }
};

class Solution {
public:
    int change(int sum,vector<int>& coins) {
        int n= coins.size();
        vector<int> dp(sum+1);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i]<=j)
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[sum];
    }
};

int main(){
    Solution sol;
    vector<int> coins={1,2,5};
    int sum=5;
    int ans =sol.change(sum,coins);
    cout<<ans;
    return 0;
}