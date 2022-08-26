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
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i, int j , vector<vector<char>>& grid){
        int m= grid.size();
        int n= grid[0].size();
        // out of bound 
        if(i<0 || j<0 || i>=m || j>=n )
            return;
        // already visited 
        if(grid[i][j]== '0' || grid[i][j] =='2')
            return;
        grid[i][j] = '2';
        // down
        dfs(i+1,j, grid);
        // left
        dfs(i, j-1, grid);
        // up
        dfs(i-1, j, grid);
        // right 
        dfs(i, j+1, grid);
    }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();

        if(grid.empty()) 
            return 0;

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        int count =0;
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    q.push({i,j});
                    grid[i][j] ='2';
                    while(q.size()){
                        auto node= q.front();
                        q.pop();
                        int u= node.first;
                        int v= node.second;

                        for(auto dir:dirs){
                            int nrow= u + dir[0];
                            int ncol = v + dir[1];
                            if(nrow >=0 && nrow< m && ncol>=0 && ncol< n && grid[nrow][ncol]=='1'){
                                grid[nrow][ncol]='2';
                                 q.push({nrow,ncol});
                            }
                                   
                        }
                        
                    }
                }
            }
        }
        return count;
    }
};



int main(){

    return 0;
}