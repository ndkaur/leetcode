/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
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
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        // if(grid[0][0]==1) return 0;
        if(i>=0 && j>=0 && grid[i][j]==1) return 0;
        return f(i-1,j,grid)+f(i,j-1,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        // if(obstacleGrid[0][0]==1) return 0;
        return f(m-1,n-1,obstacleGrid);
    }
};

// memoization 
class Solution1 {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(grid[0][0]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>=0 && j>=0 && grid[i][j]==1) return 0;
        return dp[i][j]= f(i-1,j,grid,dp)+f(i,j-1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(m-1,n-1,obstacleGrid,dp);
    }
};

// tabulation 
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int down= 0;
                    int right=0;
                    if(i>0) down = dp[i-1][j];
                    if(j>0) right= dp[i][j-1];
                    dp[i][j] = down +right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid= {{0,0,0},{0,1,0},{0,0,0}};
    int ans =sol.uniquePathsWithObstacles(grid);
    cout<<ans;
    return 0;
}