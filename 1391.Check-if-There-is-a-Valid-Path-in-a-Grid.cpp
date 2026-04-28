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
    bool is_valid(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m)
            return 0;
        return 1;
    }
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int n, int m){
        if(visited[i][j])
            return;
        visited[i][j] =1;
        int up=0, down=0, left=0, right=0;

        if(grid[i][j]==1){
            left=right=1;
        }
        else if(grid[i][j]==2){
            up=down=1;
        }
        else if(grid[i][j]==3){
            left=down =1;
        }
        else if(grid[i][j]==4){
            right=down=1;
        }
        else if(grid[i][j]==5){
            left=up = 1;
        }
        else{
            right =up=1;
        }

        if(up){
            int ni = i-1;
            int nj = j; 
            // valid and all down dirs that can recive up
            if(is_valid(ni, nj, grid, n, m) && (grid[ni][nj]==2 || grid[ni][nj]==3 || grid[ni][nj]==4)){
                dfs(ni, nj, grid, visited, n, m);
            }
        }

        if(down){
            int ni = i+1;
            int nj = j;
            if(is_valid(ni, nj, grid, n,m) && (grid[ni][nj]==2 || grid[ni][nj]==5 || grid[ni][nj]==6)){
                dfs(ni, nj, grid, visited, n, m);
            }
        }

        if(left){
            int ni = i;
            int nj = j-1;
            if(is_valid(ni, nj,grid, n,m) && (grid[ni][nj]==1 || grid[ni][nj]==4 || grid[ni][nj]==6)){
                dfs(ni, nj, grid, visited, n, m);
            }
        }

        if(right){
            int ni =i; 
            int nj = j+1;
            if(is_valid(ni, nj, grid, n,m) && (grid[ni][nj]==1 || grid[ni][nj]==3 || grid[ni][nj]==5)){
                dfs(ni, nj, grid, visited, n, m);
            }
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        dfs(0,0, grid, visited, n, m);
        return visited[n-1][m-1];
    }
};

// there are two things:- 
// 1. the two possible directions for the curr idx
// 2. the possiblity that new dir is valid, and is able to recive the incoming path 

// new dir is up-> then new cell can revive when from path down, so all with down availble will be eligible 

// 1-> left, right
// 2 -> up down 
// 3-> left, down
// 4-> right, down
// 5-> left, up
// 6-> right, up 

int main(){

    return 0;
}