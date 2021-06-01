/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
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
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(n==1)
            return triangle[0][0];
        return help(0,0,triangle,dp);
    }
    int help(int row, int col, vector<vector<int>>& tri,vector<vector<int>>& dp){
        if(dp[row][col]!=-1)
            return dp[row][col];
        if(row == tri.size()-2){ // row=1
            dp[row][col] = tri[row][col]+min(tri[row+1][col],tri[row+1][col+1]);
            return dp[row][col];
        }

        dp[row][col] = tri[row][col]+ min(help(row+1,col,tri,dp), help(row+1,col+1,tri,dp));
        return dp[row][col];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n= triangle.size();
        if(n==1) return triangle[0][0];
        vector<int> row = triangle.back();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                row[j] = triangle[i][j] + min(row[j],row[j+1]);
            }
        }
        return row[0];
    }
};



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n= triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> tri={{2},{3,4},{6,5,7},{4,1,8,3}};
    int ans = sol.minimumTotal(tri);
    cout<<ans;
    return 0;
}