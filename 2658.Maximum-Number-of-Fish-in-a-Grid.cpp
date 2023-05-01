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


// land =0
// water >0
// visited = 11
//move from  any water non zero number 
class Solution0 {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        int ans =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    ans = max(ans,dfs(i, j, grid));
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m= grid[0].size();
        // out of bound
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0 )
            return 0 ;
        // add the value to ans then mark as visited
        int ans = grid[i][j];
        // mark as visited  by marking as land
        grid[i][j] = 0;

        return ans + dfs(i+1,j, grid)
        + dfs(i, j+1, grid) +
        dfs(i, j-1, grid)+
        dfs(i-1, j, grid);
    }
};

// dfs 
class Solution1 {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        int ans =0;
       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0 ){ // only move on water cell >0
                    ans = max(ans,dfs(i, j, grid, ans));
                }
            }
        }
        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, int& ans){
        int n = grid.size();
        int m= grid[0].size();
        // out of bound
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0 )
            return 0 ;
        
        // mark as visited by marking it as land ie 0 
        grid[i][j] = 0;

        return grid[i][j] + dfs(i+1,j, grid, ans)
        + dfs(i, j+1, grid, ans) +
        dfs(i, j-1, grid, ans)+
        dfs(i-1, j, grid, ans);
    }
};



// bfs 
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        int ans =0;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){ // not land only water
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    int fish  =0;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if(grid[r][c] > 0){ // if valid cell and water 
                            fish += grid[r][c];
                            // amrk as visited
                            grid[r][c] = 0;
                        }
                        for(auto dir:dirs){
                            int nr = r+dir[0];
                            int nc = c+ dir[1];
                            // if new directions are valid 
                            if(nr >= 0 && nr <n && nc>=0 && nc<m && grid[nr][nc]>0){
                                q.push({nr,nc});
                            }
                        }
                    }
                    ans = max(ans,fish);
                }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}