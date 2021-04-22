/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
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
    int minFallingPathSum(vector<vector<int>>& arr) {
       int n= arr.size();
       int m = arr[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       int ans =INT_MAX;
       for(int i=0;i<m;i++)
            ans= min(ans,help(arr,0,i,dp));
        return ans;
    }
    int help(vector<vector<int>>& arr, int r, int c,vector<vector<int>> &dp){
        int n=arr.size();
        int m = arr[0].size();
        if(r==n) return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            if(i==c)
                continue;
            int curr= arr[r][c]+ help(arr,r+1,i,dp);
            ans= min(ans,curr);
        }
        return dp[r][c] = ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    // vector<vector<int>> arr ={{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67} };
    vector<vector<int>> arr ={{1,2,3},{4,5,6},{7,8,9}};
    int ans = sol.minFallingPathSum(arr);
    cout<<ans;
    return 0; 
   
}