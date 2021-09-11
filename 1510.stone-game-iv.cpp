/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    bool winnerSquareGame(int n) {
        return help(n);
    }
    int help(int n){
        if(n<=0) return 0;
        for(int i=1;i*i<=n;i++){// check square root 
            if(help(n-i*i)==0) return 1;
        }
        return 0;
    }
}; // time limit exceeded 

class Solution1 {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return help(n,dp);
    }
    int help(int n,vector<int>& dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){// check square root 
            if(help(n-i*i,dp)==0) return dp[n]=1;
        }
        return dp[n]=0;
    }
};

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for(int i=0;i<n+1;i++){
            for(int k=1;k*k<=i;k++){
                if(dp[i-k*k]==false){
                    dp[i]= true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n=16;
    bool ans = sol.winnerSquareGame(n);
    cout<<ans;
    return 0;
}