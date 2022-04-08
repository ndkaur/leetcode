/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
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
    int ans=0;
    int count=1;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx;
        int starty;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) count++; 
                else if(grid[i][j]==1){ // starting point found
                    startx =i;
                    starty=j;
                }
            }
        }
        dfs(grid, startx, starty, 0);
        return ans;
    }
    void dfs(vector<vector<int>> grid, int x, int y , int zero){
        if(x<0 || x>= grid.size() ||y<0 || y>= grid[0].size() || grid[x][y]==-1)
            return ;
        if(grid[x][y]==2)
            if(count==zero){
                ans++; 
                return;
            } // if all no of spaces are visited
        grid[x][y]=-1; // visited marked
        
        dfs(grid,x+1,y,zero+1);
        dfs(grid,x-1, y, zero+1);
        dfs(grid,x, y-1, zero+1);
        dfs(grid,x,y+1,zero+1);

        grid[x][y]=0; // backtrack

    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    int ans = sol.uniquePathsIII(grid);
    cout<<ans;
    return 0;
}