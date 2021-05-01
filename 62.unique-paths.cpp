/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
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
class Solution0 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+= dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end


int main(){
    Solution sol;
    int m=3;
    int n=7;
    int ans= sol.uniquePaths(m,n);
    cout<<ans;
    return 0;
}