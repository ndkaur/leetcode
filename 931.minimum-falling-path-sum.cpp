/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
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
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
//         for(int i=0;i<n;i++){
//             dp[0][i]=matrix[0][i];
//         }
//         for(int i=1;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(j==0)
//                     dp[i][j]=matrix[i][j]+min(dp[i-1][j], dp[i-1][j+1]);
//                 else if (j==n-1)
//                     dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
//                 else if(j>0 && j<n-1){
//                     dp[i][j] = matrix[i][j]+ min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
//                 }
//             }
//         }
//         int ans = INT_MAX;
//         for(auto x:dp[dp.size()-1]){
//             ans = min(ans,x);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix){
        int n= matrix.size();
        int m = matrix[0].size();
        if(j<0 || j>=m) return 1e8;
        if(i==0) return matrix[0][j];
        int top= matrix[i][j]+ f(i-1,j,matrix);
        int left= matrix[i][j]+f(i-1,j-1,matrix);
        int rgt= matrix[i][j]+f(i-1,j+1,matrix);
        return min(top,min(left,rgt));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m= matrix[0].size(); 
        int mn= 1e8;
        for(int j=0;j<m;j++){
            mn= min(mn, f(n-1,j,matrix));
        }
        return mn;
    }
};

class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n= matrix.size();
        int m = matrix[0].size();

        if(j<0 || j>=m) return 1e9;
        if(i==0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int top= matrix[i][j]+ f(i-1,j,matrix,dp);
        int left= matrix[i][j]+f(i-1,j-1,matrix,dp);
        int rgt= matrix[i][j]+f(i-1,j+1,matrix,dp);

        return dp[i][j]=min(top,min(left,rgt));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m= matrix[0].size(); 
        int mn= 1e8;
        vector<vector<int>>dp(n, vector<int>(m,-1));
        for(int j=0;j<m;j++){
            mn= min(mn, f(n-1,j,matrix,dp));
        }
        return mn;
    }
};


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int j=0;j<m;j++){ // base case if i==0
            dp[0][j]= matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int top= matrix[i][j]+ dp[i-1][j];
                int left= matrix[i][j];
                if(j-1>=0) 
                    left+=dp[i-1][j-1];
                else 
                    left+= 1e8;

                int rgt= matrix[i][j];
                if(j+1<m)
                    rgt+=dp[i-1][j+1];
                else 
                    rgt+=1e8;
                dp[i][j]=min(top,min(left,rgt));
            }
        }   
        
        int mn= 1e8;
        for(int j=0;j<m;j++){
            mn= min(mn,dp[n-1][j]);
        }
        return mn;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<int> prev(m,0);
        for(int j=0;j<m;j++){
            prev[j]= matrix[0][j];
        }
        for(int i=1;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                int top= matrix[i][j]+ prev[j];
                int left= matrix[i][j];
                if(j-1>=0) 
                    left+=prev[j-1];
                else 
                    left+= 1e8;

                int rgt= matrix[i][j];
                if(j+1<m)
                    rgt+=prev[j+1];
                else 
                    rgt+=1e8;
                curr[j]=min(top,min(left,rgt));
            }
            prev= curr; 
        }   
        
        int mn= 1e8;
        for(int j=0;j<m;j++){
            mn= min(mn,prev[j]);
        }
        return mn;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix ={{-19,57},{-40,-5}};
    int ans= sol.minFallingPathSum(matrix);
    cout<<ans;
    return 0;
}