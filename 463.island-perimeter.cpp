/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0)
                    continue;
                perimeter=perimeter+4;
                if(j+1<c)
                    perimeter=perimeter-grid[i][j+1];//right
                if(j>0)
                    perimeter=perimeter-grid[i][j-1];//left
                if(i+1<r)
                    perimeter=perimeter-grid[i+1][j];//up
                if(i>0)
                    perimeter=perimeter-grid[i-1][j];//down
            }
        }
        return perimeter; 
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid={{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int out= sol.islandPerimeter(grid);
    cout<<out;
    return 0;
}