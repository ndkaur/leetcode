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

class Solution {
public:
    bool isSafe(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>&visited, vector<pair<int,int>> &dirs){
        int n = grid.size();
        int m= grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j])
                    q.push({i,j});
            }
        }
        int cnt  = 0;

        while(q.size()){   
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto dir:dirs){
                    int nx = x+dir.first;
                    int ny = y+dir.second;
                    if(isSafe(nx,ny, n, m) && !visited[nx][ny]){
                        if(grid[nx][ny]==1)
                            return cnt; // another island
                        q.push({nx,ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
            cnt++; 
        }
        return cnt;
    }


    void dfs(int i, int j,vector<vector<int>>& grid,vector<vector<bool>>&visited, vector<pair<int,int>> &dirs){
        int n = grid.size();
        int m= grid[0].size();
        if(!isSafe(i,j, n, m) || grid[i][j]==0 || visited[i][j]==1)
            return;

        visited[i][j] =1;
        for(auto &dir:dirs){
            int nx = i+dir.first;
            int ny = j+dir.second;
            dfs(nx, ny, grid, visited, dirs);
        } 
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<pair<int,int>> dirs= {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<bool>> visited(n, vector<bool>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                   dfs(i,j, grid, visited, dirs);
                   return bfs(grid, visited, dirs);
                }
            }
        }

        return -1;
    }
};

// [1,1,1,1,1]
// [1,0,0,0,1]
// [1,0,1,0,1]
// [1,0,0,0,1]
// [1,1,1,1,1]

// 0 1 0
// 0 0 0
// 0 0 1

int main(){

    return 0;
}