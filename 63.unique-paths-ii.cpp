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
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }
                else if(i==0 && j==0)
                    dp[i][j] = 1;
                else{
                    int up =0;
                    if(i>0)
                        up += dp[i-1][j];
                    int left = 0;
                    if(j>0)
                        left += dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};


// @lc code=end

// grid 
0 0 0
0 1 0
0 0 0

// dp 
1 1 1
1 0 1
1 1 2

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        // first row i==0  if any stone come then we cant visite rest of the coordinates 
        for(int j=0; j<m; j++){
            if(grid[0][j]!=1) // no stone present 
                dp[0][j]=1; // 
            else // stone present 
                break;
        }
        // first col j==0 if any stone come then we cant visite rest of the coordinates 
        for(int i=0; i<n; i++){
            if(grid[i][0]!=1) // no stone 
                dp[i][0] =1; // one path possible to reach that coordinate 
            else  // stone came 
                break; // can fill the remaining 
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m ; j++){
                if(grid[i][j]==1) // stone in grid
                    dp[i][j] =0;
                else 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid= {{0,0,0},{0,1,0},{0,0,0}};
    int ans =sol.uniquePathsWithObstacles(grid);
    cout<<ans;
    return 0;
}