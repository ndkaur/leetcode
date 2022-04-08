/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
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
// class Solution0 {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int h = grid.size();
//         int w= grid[0].size();
//         vector<vector<int>> dp(h, vector<int>(w));
//         for(int row=0;row<h;row++){
//             for(int col=0;col<w;col++){
//                 if(row==0 && col==0)
//                     dp[row][col] = grid[row][col];
//                 else 
//                     dp[row][col] = grid[row][col]+min(((row==0) ? inf:dp[row-1][col]), ((col==0) ? inf:dp[row][col-1]));
//             }
//         }
//         return dp[h-1][w-1];
//     }
// };

// class Solution1 {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int h = grid.size();
//         int w= grid[0].size();
//         vector<vector<int>> dp(h, vector<int>(w,grid[0][0]));
//         for(int row=1;row<h;row++)
//             dp[row][0]= dp[row-1][0]+grid[row][0];
//         for(int col=1;col<w;col++)
//             dp[0][col] = dp[0][col-1] + grid[0][col];
//         for(int row=1;row<h;row++){
//             for(int col=1;col<w;col++){
//                 dp[row][col] = grid[row][col]+min(dp[row-1][col],dp[row][col-1]);
//             }
//         }
//         return dp[h-1][w-1];
//     }
// };

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int h = grid.size();
//         int w= grid[0].size();
//         vector<int> dp(h, grid[0][0]);
//         for(int row=1;row<h;row++)
//             dp[row] = dp[row-1]+grid[row][0];
//         for(int col =1 ;col<w;col++){
//             dp[0] += grid[0][col];
//             for(int row=1;row<h;row++){
//                 dp[row]= grid[row][col]+ min(dp[row],dp[row-1]);
//             }
//         }
//         return dp[h-1];
//     }
// };

// recursion 
class Solution0 {
public:
    int f(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        int up = grid[i][j]+ f(i-1,j, grid);
        int left= grid[i][j]+ f(i,j-1, grid);
        return min(up,left);
    } 
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(); 
       int n= grid[0].size();
       return f(m-1,n-1, grid);
    }
};

// memoization 
class Solution1 {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j]+ f(i-1,j, dp,grid);
        int left= grid[i][j]+ f(i,j-1,dp, grid);
        return dp[i][j]=min(up,left);
    } 
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(); 
       int n= grid[0].size();
       vector<vector<int>> dp(m, vector<int>(n,-1));
       return f(m-1,n-1,dp,grid);
    }
};

// tabulation 
class Solution2 {
public: 
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(); 
       int n= grid[0].size();
       vector<vector<int>> dp(m, vector<int>(n,0));
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(i==0 && j==0) dp[i][j]=grid[i][j];
               else{
                    int up= grid[i][j];
                    if(i>0)
                        up+=dp[i-1][j];
                    else up+= 1e9; 
                    
                    int left=grid[i][j];
                    if(j>0)
                        left+=dp[i][j-1];
                    else left+=1e9;

                    dp[i][j]= min(left,up);
               }
           }
       }
       return dp[m-1][n-1];
    }
};


class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size(); 
       int n= grid[0].size();
       vector<int>prev(n,0);
       for(int i=0;i<m;i++){
           vector<int> curr(n,0);
           for(int j=0;j<n;j++){
               if(i==0 && j==0) curr[j]=grid[i][j];
               else{
                    int up= grid[i][j];
                    if(i>0)
                        up+=prev[j];
                    else up+= 1e9;
                    
                    int left=grid[i][j];
                    if(j>0)
                        left+=curr[j-1];
                    else left+=1e9;

                    curr[j]= min(left,up);
               }
           }
           prev= curr; 
       }
       return prev[n-1];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid ={{1,2,3},{4,5,6}};
    int ans= sol.minPathSum(grid);
    cout<<ans;
    return 0;
}