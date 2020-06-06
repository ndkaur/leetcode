/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
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
    int countNegatives(vector<vector<int>>& grid) {
        // int len =grid.size();
        int negcount =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0)
                  negcount ++;
                }  
        }
        return negcount;
    }
};
// @lc code=end  


int main(){
    Solution sol;
    vector<vector<int>> grid;
    int i,j,negcount;
    grid={{4,3,2,-1},{-3,-2,-1,-1}};
    negcount=sol.countNegatives(grid);
    cout<<negcount;
    return 0;
}