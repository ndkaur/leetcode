/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
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


class Solution { // dp on square
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        // the diagonal, above , left -> min +1 == max side of the curr position square 
        // dp reprents -> what is the side of the bigest square ending at that point i,j
        // as well as the no of square having the curr point as their right mode bottom point 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0){
                    dp[i][j] = matrix[i][j]; // incase the matrix val is 1
                }
                if(i>0 && j>0 && matrix[i][j]>0){
                    dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};


class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m= matrix[0].size();
        dp = vector<vector<int>>(n,vector<int>(m,0));

        // storing prefix sum in dp
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j] =  matrix[i][j] + (i>0 ? dp[i-1][j]:0) + 
                            (j>0 ? dp[i][j-1]:0) 
                            - ((i>0 && j>0) ? dp[i-1][j-1]:0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // (row1, col1)->(row2, col2)
        // total sum - small box sum 
        // but some boxes get subtracted twice -> add them ones
        int ans = dp[row2][col2] - (row1>0 ? dp[row1-1][col2]:0) 
                - (col1>0 ? dp[row2][col1-1]:0) 
                + (row1>0 && col1>0 ? dp[row1-1][col1-1]:0);
        return ans;
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end


int main(){

    return 0;
}