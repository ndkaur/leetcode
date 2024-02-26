/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
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

//DFS
// time O(R∗ C) 
// space O(R∗ C)
class Solution0 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h= grid.size();
        int w= grid[0].size();
        int ans =0;
        vector<vector<bool>> seen(h,vector<bool>(w));
        for(int r=0;r<h;r++){
            for(int c=0;c<w;c++){
                ans= max(ans,help(grid,seen,r,c));
            }
        }
        return ans;
    }
    int help(vector<vector<int>>& grid, vector<vector<bool>>& seen, int r, int c){
        // out of bound || a;ready visited || is 0
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || seen[r][c] || grid[r][c]==0)
            return 0;
        seen[r][c] =true;
        return (1+ help(grid,seen,r+1,c) + help(grid,seen,r-1,c)+ help(grid,seen,r,c+1)+ help(grid,seen,r,c-1));
    }
};


class Solution {
    int biggest_island = 0;
    int curr_island = 0;
public:
    
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
            return;
        }
        if (grid[i][j] == 1) {
            curr_island++;
            grid[i][j] = 0;
        }
        
        dfs(i+1, j, rows, cols, grid);
        dfs(i-1, j, rows, cols, grid);
        dfs(i, j+1, rows, cols, grid);
        dfs(i, j-1, rows, cols, grid);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, rows, cols, grid);
                    biggest_island = max(biggest_island, curr_island);
                    curr_island = 0;
                }
            }
        }

        return biggest_island;
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    ans = max(ans, bfs(i,j,grid));
            }
        }
        return ans;
    }
    int bfs(int i, int j , vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        int area=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 2;
        vector<vector<int>> dirs= {{-1,0},{0,1},{1,0},{0,-1}};
        while(q.size()){
            auto node = q.front();
            q.pop();
            int u= node.first;
            int v= node.second;
            for(auto dir:dirs){
                int nrow= u+ dir[0];
                int ncol = v+ dir[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    area++;
                    q.push({nrow,ncol});
                }
            }
        }
        return area;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid= {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int ans = sol.maxAreaOfIsland(grid);
    cout<<ans;
    return 0;
}