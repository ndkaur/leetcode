/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
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

// a+b = total 
// a-b =diff -> b = -diff+a
// a+a-diff=total -> 2a= total+diff -> a = (t+d)/2;

class Solution { // top down 
public:
    int stoneGameII(vector<int>& piles) {
        int n= piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int diff = help(piles,0,1,dp);
        return (sum+diff)/2;
    }
    int help(vector<int>& piles,int i,int m , vector<vector<int>>& dp){
        int n= piles.size();
        if(i==n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int sum=0;
        int ans=INT_MIN;
        // 1 <= X <= 2M  
        // X =  remaining pile  i=0, j is ahead of i
        // X = j-i + 1   
        for(int j=i;j<n && j-i+1<=2*m;j++){
            sum+=piles[j];
            ans = max(ans,sum-help(piles,j+1, max(m,j-i+1),dp));
        }
        return dp[i][m]=ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> piles ={1,2,3,4,5,100};
    int ans = sol.stoneGameII(piles);
    cout<<ans;
    return 0;
}