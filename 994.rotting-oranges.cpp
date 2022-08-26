/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
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
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
    
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        int time=0;
        vector<pair<int,int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(fresh!=0  && !q.empty()){
            // there can be alot of rotten oranges 
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                int r1 = q.front().first;
                int r2 = q.front().second;
                q.pop();

                for(auto dir:dirs){
                    int nrow= r1 + dir.first;
                    int ncol = r2 + dir.second;
                    // orange fresh then 
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.push({nrow, ncol});
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};

// @lc code=end


int main(){

    return 0;
}