/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
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
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle){
//         int n= triangle.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         if(n==1)
//             return triangle[0][0];
//         return help(0,0,triangle,dp);
//     }
//     int help(int row, int col, vector<vector<int>>& tri,vector<vector<int>>& dp){
//         if(dp[row][col]!=-1)
//             return dp[row][col];
//         if(row == tri.size()-2){ // row=1
//             dp[row][col] = tri[row][col]+min(tri[row+1][col],tri[row+1][col+1]);
//             return dp[row][col];
//         }

//         dp[row][col] = tri[row][col]+ min(help(row+1,col,tri,dp), help(row+1,col+1,tri,dp));
//         return dp[row][col];
//     }
// };

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle){
//         int n= triangle.size();
//         if(n==1) return triangle[0][0];
//         vector<int> row = triangle.back();
//         for(int i=n-2;i>=0;i--){
//             for(int j=0;j<triangle[i].size();j++){
//                 row[j] = triangle[i][j] + min(row[j],row[j+1]);
//             }
//         }
//         return row[0];
//     }
// };



// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle){
//         int n= triangle.size();
//         for(int i=n-2;i>=0;i--){
//             for(int j=0;j<triangle[i].size();j++){
//                 triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
//             }
//         }
//         return triangle[0][0];
//     }
// };


// recursion
class Solution0 {
public:
    int f(int i, int j, vector<vector<int>>& triangle){
        int m = triangle.size();
        int n = triangle[0].size();
        if(i==m-1) return triangle[m-1][j];
        int down= triangle[i][j]+ f(i+1,j, triangle);
        int diag= triangle[i][j]+ f(i+1,j+1, triangle);
        return min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle){
        return f(0,0, triangle);
    }
};

// memoization
class Solution1 {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int m = triangle.size();
        if(i==m-1) return triangle[m-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down= triangle[i][j]+ f(i+1,j, triangle,dp);
        int diag= triangle[i][j]+ f(i+1,j+1, triangle,dp);
        return dp[i][j]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle){
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m,-1));
        return f(0,0, triangle,dp);
    }
};  

// tabulation 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[m-1][j]= triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j]+ dp[i+1][j];
                int diag= triangle[i][j]+ dp[i+1][j+1];
                dp[i][j] = min(down, diag);  
            }
        } 
        return dp[0][0];
    }
};

// space optimization 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int m = triangle.size();
        vector<int> prev(n,0);
        for(int j=0;j<m;j++){
            prev[j]= triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j]+ prev[j];
                int diag= triangle[i][j]+ prev [j+1];
                curr[j] = min(down, diag);  
            }
            prev= curr;
        }
        return prev[0]; 
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