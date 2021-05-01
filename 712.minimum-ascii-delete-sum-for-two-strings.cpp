/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
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
    int minimumDeleteSum(string s1, string s2) {
        int n= s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=1;j<=m;j++)
            dp[0][j] = dp[0][j-1]+s2[j-1];
        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][0]+s1[i-1];
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

int main(){ 
    Solution sol;
    string s1="delete";
    string s2="leet";
    int ans= sol.minimumDeleteSum(s1,s2);
    cout<<ans;
    return 0;
}