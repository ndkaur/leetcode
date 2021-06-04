/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

//DFS
class Solution0 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h= grid.size();
        int w= grid[0].size();
        int ans =0;
        vector<vector<bool>> seen(h,vector<bool>(w));
        for(int r=0;r<h;r++){
            for(int c=0;c<w;c++){
                ans= max(ans,help(grid,seen,r,c));
            }
        }
        return ans;
    }
    int help(vector<vector<int>>& grid, vector<vector<bool>>& seen, int r, int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || seen[r][c] || grid[r][c]==0)
            return 0;
        seen[r][c] =true;
        return (1+ help(grid,seen,r+1,c) + help(grid,seen,r-1,c)+ help(grid,seen,r,c+1)+ help(grid,seen,r,c-1));
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h= grid.size();
        int w= grid[0].size();
        int ans =0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j]==1)
                    ans= max(ans,area(grid,i,j));
            }
        }
        return ans;
    }
    int area(vector<vector<int>>& grid,int row, int col){
        int h=grid.size();
        int w= grid[0].size();
        int area=1;
        queue<pair<int,int>> mq;
        mq.push({row,col});
        grid[row][col]=2; //visited
        vector<int> dir={-1,0,1,0,-1};
        while(!mq.empty()){
            int z = mq.front().first;
            int x= mq.front().second;
            mq.pop();
            for(int i=0;i<4;i++){
                int r= z+dir[i];
                int c= x+dir[i+1];
                if(r>=0 && r<h && c<w && c>=0 && grid[r][c]==1){
                    grid[r][c]=2;//visited
                    area++;
                    mq.push({r,c});
                }
            } 
        }
        return area;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid= {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int ans = sol.maxAreaOfIsland(grid);
    cout<<ans;
    return 0;
}