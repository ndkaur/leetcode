/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
      
        for(;k>0;k--){
            int prev= grid[m-1][n-1];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int temp=grid[i][j];
                    grid[i][j]=prev;
                    prev=temp;
                }
            }
        }
        return grid;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid={{1,2,3},{4,5,6},{7,8,9}};
    int k=9;
    vector<vector<int>> ans=sol.shiftGrid(grid,k);
    for(auto x:ans){
        print(x);
    }
    return 0;
}