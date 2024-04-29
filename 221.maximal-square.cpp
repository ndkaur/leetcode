/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
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
    int f(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();
        if(i>=n || j>=m)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(matrix[i][j]=='0')
            return dp[i][j] = 0;
        
        dp[i][j] = 1+min(min(f(i+1, j,matrix, dp), f(i, j+1, matrix, dp)), f(i+1, j+1, matrix, dp));
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n==0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int mx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mx = max(mx, f(i,j,matrix, dp));
            }
        }
        return mx*mx;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        int mx = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(mat[i-1][j-1] =='1'){
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    mx = max(mx, dp[i][j]);
                }
                else 
                    dp[i][j] = 0;
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                cout<<dp[i][j]<<',';
            }
            cout<<endl;
        }
        return mx*mx; // area
    }
};
// @lc code=end


int main(){

    return 0;
}