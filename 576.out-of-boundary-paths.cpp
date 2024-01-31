/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
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

// recursion
class Solution0 {  // O(4^n) -> 4 cases 
public:
    int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int row, int col) {
        if(row<0 || row==m || col<0 || col==n)
            return 1;
        if(maxMove==0)
            return 0;
        // {-1,0}, {1,0} , {0,-1}, {0,1}
        return findPaths(m, n, maxMove-1, row-1, col) + findPaths(m, n, maxMove-1, row+1, col) + findPaths(m, n, maxMove-1, row, col-1) +findPaths(m, n, maxMove-1, row, col-1);
    }
};

// memoization 
class Solution1 { // O(n*m*mx)
public:
    int mod = 1e9+7;
    int f(int i, int j, int mx, int m, int n, vector<pair<int,int>>& dirs,  vector<vector<vector<int>>>& dp){
        if(i<0 || i==m || j<0 || j==n) // out of boundary, main condition for ans
            return 1;
        if(mx==0) // out of moves 
            return 0;
        if(dp[i][j][mx]!=-1)
            return dp[i][j][mx];
        long long ans = 0;

        for(auto dir:dirs){
            int newRow = i+dir.first;
            int newCol = j+dir.second;
            ans = (ans+ f(newRow, newCol, mx-1, m, n, dirs, dp))%mod;
        }
        
        return dp[i][j][mx] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1, -1)));
        return f(startRow, startColumn, maxMove, m,n, dirs, dp);
    }
};


// tabulation 
class Solution {  // O(m*n*mx)
public:
    int mod = 1e9+7;
    int findPaths(int m, int n, int mx, int row, int col) {
       vector<vector<int>> dp(m, vector<int>(n, 0));
       dp[row][col] = 1;
       int cnt = 0;

       for(int moves=1; moves<=mx; moves++){
           vector<vector<int>> temp(m, vector<int>(n));
           for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(i==m-1)
                        cnt = (cnt+dp[i][j])%mod;
                    if(j==n-1)
                        cnt = (cnt+dp[i][j])%mod;
                    if(i==0)
                        cnt = (cnt+dp[i][j])%mod;
                    if(j==0)
                        cnt = (cnt+dp[i][j])%mod;
                    // {-1,0}, {1,0} , {0,-1}, {0,1}
                    temp[i][j] = (((i>0 ? dp[i-1][j] : 0) + (i<m-1 ? dp[i+1][j]:0))%mod + ((j>0 ? dp[i][j-1]:0) + (j<n-1 ? dp[i][j+1]:0))%mod)%mod;
               }
           }
           dp = temp;
       }
       return cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}