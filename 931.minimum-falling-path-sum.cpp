/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j], dp[i-1][j+1]);
                else if (j==n-1)
                    dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else if(j>0 && j<n-1){
                    dp[i][j] = matrix[i][j]+ min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                }
            }
        }
        int ans = INT_MAX;
        for(auto x:dp[dp.size()-1]){
            ans = min(ans,x);
        }
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix ={{-48}};
    int ans= sol.minFallingPathSum(matrix);
    cout<<ans;
    return 0;
}