/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
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
// dfs 
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
      
        int cnt=0;
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i,0, grid);
            }
            if(grid[i][m-1] == 1){
                dfs(i, m-1, grid);
            }
        }
        
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1){
                dfs(0, j, grid);
            }
            if(grid[n-1][j] == 1){
                dfs(n-1, j, grid);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    cnt++;    
            }
        }
        return cnt;
    }
    void dfs(int i, int j, vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!= 1)
            return;
        grid[i][j] = 2;
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
};

// bfs c// o(n*m*4)   //O(n*m)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                     if(grid[i][j] == 1){
                         q.push({i,j});
                         visited[i][j] =1;
                     }
                }
            }
        }
        vector<pair<int,int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};
        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(auto dir: dirs){
                int nrow = r+ dir.first;
                int ncol = c + dir.second;
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] ==1 && visited[nrow][ncol] == 0){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] =1;
                }
            }
        }
        int cnt =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] ==1 && visited[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};



// @lc code=end



int main(){

    return 0;
}