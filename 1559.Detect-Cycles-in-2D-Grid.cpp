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
    vector<pair<int,int>> dirs= {{0,1},{-1,0},{0,-1},{1,0}};

    bool check(int i, int j, int pi, int pj,  vector<vector<char>>& grid, int n, int m, vector<vector<int>>& visited){  
        visited[i][j] = 1;
    
        for(auto dir:dirs){
            int ni = i+dir.first;
            int nj = j+dir.second;

            if(ni<0 || ni>=n || nj<0 || nj>=m) // out of bound
                continue;
            if(grid[ni][nj]!=grid[i][j]) // char match 
                continue;
            
            if(!visited[ni][nj]){ // not visited go ahead 
                if(check(ni, nj, i, j, grid, n, m, visited)) // continue dfs
                    return true;
            }
            else if(ni!=pi || nj!=pj)
                return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
     
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j]){
                    if(check(i, j, -1, -1, grid, n, m, visited))
                        return true;
                }
            }
        }
        return false;
    }
};

// cyclye is when the idx we reach is not visited then move, but if its already visited but not visited by its parents then its a cycle.
// if visited by someone else not parents then its not a cycle.