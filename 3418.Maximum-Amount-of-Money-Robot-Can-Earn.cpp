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


class Solution {
public:
    int f(int i, int j, int neu, vector<vector<vector<int>>>& dp, vector<vector<int>>& coins, int n, int m){
        if(i==n-1 && j==m-1){ // base case
            if(coins[i][j]>=0)
                return coins[i][j];
            else {
                if(neu>0) // use neutralize, nothing added 
                    return 0;
                else 
                    return coins[i][j];
            }
        }

        if(dp[i][j][neu]!=-1e9+7)
            return dp[i][j][neu];

        int val = coins[i][j];

        int ans = INT_MIN;

        if(coins[i][j]>=0){ // +ve
            if(i+1<n) // down
                ans =max(ans, val + f(i+1, j, neu, dp, coins, n, m));
            if(j+1<m) // right
                ans = max(ans,val + f(i, j+1, neu, dp, coins, n, m));
        }
        else{ // -ve -> skip or add as -ve let robber rob
            if(neu>0){
                if(i+1<n) // skip down
                    ans = max(ans, f(i+1, j, neu-1, dp, coins, n, m));
                if(j+1<m) // skip right
                    ans = max(ans, f(i, j+1, neu-1,  dp, coins, n, m));
            }
            // add
            if(i+1<n) // down 
                ans = max(ans, val + f(i+1, j, neu, dp, coins, n, m));
            if(j+1<m){ // right
                ans = max(ans, val + f(i, j+1, neu, dp, coins, n, m));
            }
        }

        return dp[i][j][neu]= ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9+7)));
        
        return f(0,0,2, dp, coins, n, m);
    }
};

int main(){

    return 0;
}