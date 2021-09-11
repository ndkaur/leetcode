/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
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
class Solution0 {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(auto it:mines){
            int x= it[0];
            int y= it[1];
            grid[x][y]=0;
        }
        vector<vector<int>> left, right, top, bottom;
        left=right=top=bottom = grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x= n-i-1;
                int y= n-j-1;
                if((i>0) && top[i][j] ) 
                    top[i][j] += top[i-1][j];
                if((j>0) && left[i][j])
                    left[i][j]+= left[i][j-1];
                if(x+1<n && bottom[x][y])
                    bottom[x][y] += bottom[x+1][y];
                if(y+1<n && right[x][y])
                    right[x][y]+= right[x][y+1];
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, min({left[i][j],right[i][j],bottom[i][j],top[i][j]}));
            }
        }
        return ans;
    }
};


class Solution1 {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(auto it:mines){
            int x= it[0];
            int y= it[1];
            grid[x][y]=0;
        }
        int ans =0;
        if(mines.size()<n*n) ans =1;
        vector<vector<int>> left(n,vector<int>(n));
        vector<vector<int>> right(n,vector<int>(n));
        vector<vector<int>> bottom(n,vector<int>(n));
        vector<vector<int>> top(n,vector<int>(n));
        // for top, left
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    top[i][j] = (i-1>=0)? top[i-1][j]+1 :1;
                    left[i][j] = (j-1>=0) ? left[i][j-1]+1 :1;
                }
                else {
                    left[i][j] =0;
                    right[i][j]=0;
                }
            }
        }
        // for bottom and right have to count from other direction 
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    bottom[i][j] = (i+1<n)?bottom[i+1][j]+1:1;
                    right[i][j] = (j+1<n) ? right[i][j+1]+1 : 1;
                }
                else{
                    bottom[i][j]=0;
                    right[i][j]=0;
                }
                ans = max(ans, min({left[i][j],right[i][j],bottom[i][j],top[i][j]}));
            }
        }
        return ans;
    }
};


class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n,vector<int>(n,1));
        for(auto it:mines){
            int x= it[0];
            int y= it[1];
            grid[x][y]=0;
        }
        int ans =0;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        // left
        for(int i=0;i<n;i++){  
            int count=0;
            for(int j=0;j<n;j++){
                grid[i][j] ? count++ : count=0;
                dp[i][j]= min(dp[i][j],count);
            }
        }
        // right 
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                grid[i][j]?count++ : count =0;
                dp[i][j] = min(dp[i][j],count);
            }
        }
        // top
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                grid[j][i] ? c++ : c=0;
                dp[j][i]= min(dp[j][i],c);
            }
        }
        //bottom
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=n-1;j>=0;j--){
                grid[j][i] ? c++ : c=0;
                dp[j][i] = min(c,dp[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans ;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=3;
    vector<vector<int>> mines={{0,0}};
    int ans = sol.orderOfLargestPlusSign(n,mines);
    cout<<ans;
   return 0;
}