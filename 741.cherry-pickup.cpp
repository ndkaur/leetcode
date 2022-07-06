/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
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

// instead of moving one time from (0,0) to (n-1,n-1) and again moving from (n-1,n-1) to (0,0)
//  lets move from starting 0,0 to n one time by taking two robots who visit all possible cases 

class Solution0 {
public:
    int f(int r1, int c1, int r2, int c2, vector<vector<int>>& grid){
        int row= grid.size();
        int col= grid[0].size();
        // out of bound 
        if(r1>= row || r2>=row || c1>=col || c2>=col || 
           grid[r1][c1]==-1 || grid[r2][c2]==-1) 
            return -1e8;
        // destination condition
        if(r1== row-1 && c1== col-1){
            return grid[r1][c1];
        } 
        int chery=0;
        //base condition 
        if(r1==r2 && c1==c2){
            chery += grid[r1][c1];
        } else{
            chery+= grid[r1][c1]+ grid[r2][c2];
        }

        int f1= f(r1, c1+1, r2, c2+1, grid);// hh
        int f2= f(r1+1,c1,r2, c2+1, grid); // vh
        int f3= f(r1, c1+1, r2+1,c2, grid); // hv 
        int f4= f(r1+1, c1, r2+1, c2, grid); // vv

        chery += max({f1,f2,f3,f4});
        return chery;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return max(0,f(0,0,0,0,grid));
    }
};

class Solution1 {
public:
    int f(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp){
        int row= grid.size();
        int col= grid[0].size();
        // out of bound 
         if(r1>= row || r2>=row || c1>=col || c2>=col || 
           grid[r1][c1]==-1 || grid[r2][c2]==-1) 
            return -1e8;
        // destination condition
        if(r1== row-1 && c1== col-1){
            return grid[r1][c1];
        } 
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        int chery=0;
        //base condition 
        if(r1==r2 && c1==c2){
            chery += grid[r1][c1];
        } else{
            chery+= grid[r1][c1]+ grid[r2][c2];
        }

        int f1= f(r1, c1+1, r2, c2+1, grid,dp);// hh
        int f2= f(r1+1,c1,r2, c2+1, grid,dp); // vh
        int f3= f(r1, c1+1, r2+1,c2, grid,dp); // hv 
        int f4= f(r1+1, c1, r2+1, c2, grid,dp); // vv

        chery += max({f1,f2,f3,f4});
        dp[r1][c1][r2][c2]= chery;
        return chery;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,f(0,0,0,0,grid,dp));
    }
};

// 3d dp 
class Solution2 {
public:
    int f(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int row= grid.size();
        int col= grid[0].size();
        int c2= r1+c1-r2; // r1+c1= r2+c2
        // out of bound 
         if(r1>= row || r2>=row || c1>=col || c2>=col || 
           grid[r1][c1]==-1 || grid[r2][c2]==-1) 
            return -1e8;
        // destination condition
        if(r1== row-1 && c1== col-1){
            return grid[r1][c1];
        } 
        if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
        int chery=0;
        //base condition 
        if(r1==r2 && c1==c2){
            chery += grid[r1][c1];
        } else{
            chery+= grid[r1][c1]+ grid[r2][c2];
        }

        int f1= f(r1, c1+1, r2, grid,dp);// hh
        int f2= f(r1+1,c1,r2, grid,dp); // vh
        int f3= f(r1, c1+1, r2+1, grid,dp); // hv 
        int f4= f(r1+1, c1, r2+1, grid,dp); // vv

        chery += max({f1,f2,f3,f4});
        dp[r1][c1][r2]= chery;
        return chery;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,f(0,0,0,grid,dp));
    }
};

class Solution {
public:
    int maxm(int a, int b, int c, int d){
        return max(max(a,b),max(c,d));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n][n][n][n];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(grid[i][j]==-1 || grid[k][l]==-1){
                            dp[i][j][k][l] =-1e8;
                            continue;
                        }
                        int c=0;
                        if(i==k && j==l)
                            c= grid[i][j];
                        else 
                            c= grid[i][j]+grid[k][l];
                        if(i==0 && j==0){
                            dp[i][j][k][l]=c;
                            continue;
                        }
                        int f1 = i>0 && k>0 ? dp[i-1][j][k-1][l] +c :-1e8;
                        int f2= i>0 && l>0 ? dp[i-1][j][k][l-1]+c :-1e8;
                        int f3= j>0 && k>0 ? dp[i][j-1][k-1][l] +c : -1e8;
                        int f4= j>0 && l>0 ? dp[i][j-1][k][l-1] +c : -1e8;
                        dp[i][j][k][l]= maxm(f1,f2,f3,f4);
                    }
                }
            }
        }
        return max(0,dp[n-1][n-1][n-1][n-1]);
    }
};

// @lc code=end


int main(){

    return 0;
}