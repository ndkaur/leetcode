/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
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

// recursive 
// Time Complexity : O((N*M)*4^(N*M))

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int ans =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // i , j, marix,  prev len 
               ans = max(ans,dfs(i, j, matrix, -1));
            }
        }
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& matrix, int prevlen){
        int n= matrix.size();
        int m = matrix[0].size();
        // incr order prev < cureent 
        if(i<0 || j<0 || i==n || j==m || matrix[i][j] <= prevlen)
            return 0;

        int left = dfs(i, j-1, matrix, matrix[i][j]);
        int right = dfs(i, j+1, matrix, matrix[i][j]);
        int up = dfs(i-1, j, matrix, matrix[i][j]);
        int down = dfs(i+1, j, matrix, matrix[i][j]);

        return max({left, right, up, down}) + 1;
    }
};


// memoization
// Time Complexity : O(NM)
// Space Complexity : O(NM)

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // i , j, marix,  prev len 
               ans = max(ans,dfs(i, j, matrix, -1 , dp));
            }
        }
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& matrix, int prevlen, vector<vector<int>>& dp){
        int n= matrix.size();
        int m = matrix[0].size();
        // incr order prev < current 
        if(i<0 || j<0 || i==n || j==m || matrix[i][j] <= prevlen) // termination conditions
            return 0;
        if(dp[i][j])
            return dp[i][j];
        int left = dfs(i, j-1, matrix, matrix[i][j], dp);
        int right = dfs(i, j+1, matrix, matrix[i][j], dp);
        int up = dfs(i-1, j, matrix, matrix[i][j], dp);
        int down = dfs(i+1, j, matrix, matrix[i][j],dp);

        return dp[i][j] = max({left, right, up, down}) + 1 ;
    }
};

// @lc code=end


int main(){

    return 0;
}