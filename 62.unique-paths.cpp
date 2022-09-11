/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
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
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n,1);
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[j]+= dp[j-1];
//             }
//         }
//         return dp[n-1];
//     }
// };

// recursion - top down approach // time limit exceeded
class Solution0 { // time- O(2^ m*n)
public:
    int f(int i,int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        int up= f(i-1,j);
        int left= f(i,j-1);
        return up+left;
    }
    int uniquePaths(int m, int n) {
        return f(m-1,n-1);
    }
};

//  MEMOIZATION - TOP DOWN 
class Solution1 { //time- O(n*m)
public:
    int f(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up= f(i-1,j,dp);
        int left= f(i,j,dp);
        return dp[i][j]= up+left;
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n,-1));
       return f(m-1,n-1,dp);
    }
};

//  tabulation - top down 
class Solution2 {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n,-1));
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(i==0 && j==0) dp[i][j]=1;
               else{
                   int down=0;
                   int right =0;
                   if(i>0) down= dp[i-1][j];
                   if(j>0) right=dp[i][j-1];
                    dp[i][j]= down +right;
               }
           }
       }
       return dp[m-1][n-1];
    }
};

//  space optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<int> prev(n,0);
       for(int i=0;i<m;i++){
           vector<int> curr(n,0);
           for(int j=0;j<n;j++){
               if(i==0 && j==0) curr[j]=1;
               else{
                   int down=0;
                   int right =0;
                   if(i>0) down= prev[j];
                   if(j>0) right=curr[j-1];
                    curr[j]= down +right;
               }
           }
           prev= curr;
       }
       return prev[n-1];
    }
};




// @lc code=end

class Solution {
public:
    int uniquePaths(int m, int n) {
        // fill the full dp with 1 
        // int first row and first col i=0 and j=0 our dp = 1 
        // cause we have 1 way to reach to it 
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


int main(){
    Solution sol;
    int m=3;
    int n=7;
    int ans= sol.uniquePaths(m,n);
    cout<<ans;
    return 0;
}