/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
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
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w= grid[0].size();
        vector<vector<int>> dp(h, vector<int>(w));
        for(int row=0;row<h;row++){
            for(int col=0;col<w;col++){
                if(row==0 && col==0)
                    dp[row][col] = grid[row][col];
                else 
                    dp[row][col] = grid[row][col]+min(((row==0) ? inf:dp[row-1][col]), ((col==0) ? inf:dp[row][col-1]));
            }
        }
        return dp[h-1][w-1];
    }
};

class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w= grid[0].size();
        vector<vector<int>> dp(h, vector<int>(w,grid[0][0]));
        for(int row=1;row<h;row++)
            dp[row][0]= dp[row-1][0]+grid[row][0];
        for(int col=1;col<w;col++)
            dp[0][col] = dp[0][col-1] + grid[0][col];
        for(int row=1;row<h;row++){
            for(int col=1;col<w;col++){
                dp[row][col] = grid[row][col]+min(dp[row-1][col],dp[row][col-1]);
            }
        }
        return dp[h-1][w-1];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int h = grid.size();
        int w= grid[0].size();
        vector<int> dp(h, grid[0][0]);
        for(int row=1;row<h;row++)
            dp[row] = dp[row-1]+grid[row][0];
        for(int col =1 ;col<w;col++){
            dp[0] += grid[0][col];
            for(int row=1;row<h;row++){
                dp[row]= grid[row][col]+ min(dp[row],dp[row-1]);
            }
        }
        return dp[h-1];
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