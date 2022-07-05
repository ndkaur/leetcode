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

//  recursion

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini= min(mini,f(n-1,j,matrix));
        }
        return mini;
    }
     int f(int i, int j, vector<vector<int>>& grid){
        if(j<0 || j>= grid[0].size()) return 1e9;
        if(i==0) 
            return grid[0][j];
        
        int ans=INT_MAX;
        for(int k=0;k<grid[0].size();k++){
            if(k==j)
                continue;
            int curr= grid[i][j]+ f(i-1,k, grid);
            ans= min(ans, curr);
        }
        
        return ans;
    }
};

//  meomization 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini= min(mini,f(n-1,j,dp,matrix));
        }
        return mini;
    }
     int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(j<0 || j>= grid[0].size()) return 1e9;
        if(i==0) 
            return grid[0][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<grid[0].size();k++){
            if(k==j)
                continue;
            int curr= grid[i][j]+ f(i-1,k,dp, grid);
            ans= min(ans, curr);
        }
        
        return dp[i][j]= ans;
    }
};

//  tabulation 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        
        for(int j=0;j<m;j++)
            dp[0][j]= grid[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int ans=INT_MAX;
                for(int k=0;k<grid[0].size();k++){
                    if(k==j)
                        continue;
                    int curr= grid[i][j]+ dp[i-1][k];
                    ans= min(ans, curr);
                    dp[i][j]= ans;
                }
            }
        }
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini= min(mini,dp[n-1][j]);
        }
        return mini;
    }
};

//  space optimization 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        if(n==1) grid[0][0];

        vector<int> prev(m);
        
        for(int j=0;j<m;j++)
            prev[j]= grid[0][j];
        
        for(int i=1;i<n;i++){
            vector<int> curr(m);
            for(int j=0;j<m;j++){
                int ans=INT_MAX;
                for(int k=0;k<grid[0].size();k++){
                    if(k==j)
                        continue;
                    int temp= grid[i][j]+ prev[k];
                    ans= min(ans, temp);
                }
                curr[j] = ans;
            }
            prev= curr;
        }
        int mini=1e9;
        for(int j=0;j<m;j++){
            mini= min(mini,prev[j]);
        }
        return mini;
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