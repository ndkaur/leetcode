/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
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
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt =0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // dfs for islands at edges
                if(i==0 || j==0 || i==n-1 || j==m-1 && grid[i][j]==0)
                    dfs(grid,i,j);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // dfs for all other islands
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int i, int j){
        int n= grid.size();
        int  m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != 0)
            return;

        grid[i][j] = INT_MIN; // marking it visited

       
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i ,  j-1);
        dfs(grid, i ,  j+1);
    } 
};
// @lc code=end


int main(){

    return 0;
}