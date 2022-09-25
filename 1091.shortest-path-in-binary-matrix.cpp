/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
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

// O(8*n^2)=O(n^2)
//O(n)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
       
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0,0});
        
        grid[0][0] = 1;
        //-1 0 1  -1 0 1
        vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row == n-1 && col == n-1)
                return grid[row][col];
            for(auto dir: dirs){
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                    
                if(nrow >= 0 && nrow < n &&  ncol>=0 && ncol<n && grid[nrow][ncol] == 0){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = grid[row][col]+ 1;
                }
            }
        } 
        return -1;
    }
};

// @lc code=end


int main(){

    return 0;
}