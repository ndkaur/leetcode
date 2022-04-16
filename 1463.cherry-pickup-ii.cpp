/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
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

// recursion on 3d grid 
//  time - 3^ m  explonential
class Solution0 {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid){
        // outer bound case 
        if(j1<0 || j2<0 || j1>=c || j2>=c) 
            return -1e8;
        // base case - when we reach destination
        if(i==r-1){
            if(j1==j2)// both robos are at same position 
                return grid[i][j1];
            else 
                return grid[i][j1]+ grid[i][j2];
        }
        // we have to visit all the left cases/ positions - 9 cases
        // i is fixed and only j changes -> j-1  j  j+1
        int maxi=0;
        for(int dj1= -1; dj1<= +1 ; dj1++){
            for(int dj2=-1; dj2<= +1;dj2++){
                int value=0;
                if(j1==j2) // at same position 
                    value = grid[i][j1];
                else 
                    value = grid[i][j1]+ grid[i][j2];
                value += f(i+1 , j1+dj1  , j2+dj2 , r, c, grid);
                maxi= max(value, maxi);
            }
        }
        return maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        return f(0,0,c-1,r,c, grid);
    }
};

// memoization -> here it is bottom to top
// time - O(N*M*M) * 9
// Space Complexity: O(N) + O(N*M*M)
class Solution1 {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        // outer bound case 
        if(j1<0 || j2<0 || j1>=c || j2>=c) 
            return -1e8;
        // base case - when we reach destination
        if(i==r-1){
            if(j1==j2)// both robos are at same position 
                return grid[i][j1];
            else 
                return grid[i][j1]+ grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        // we have to visit all the left cases/ positions - 9 cases
        // i is fixed and only j changes -> j-1  j  j+1
        int maxi=0;
        for(int dj1= -1; dj1<= +1 ; dj1++){
            for(int dj2=-1; dj2<= +1;dj2++){
                int value=0;
                if(j1==j2) // at same position 
                    value = grid[i][j1]; 
                else 
                    value = grid[i][j1]+ grid[i][j2];
                value += f(i+1 , j1+dj1  , j2+dj2 , r, c, grid, dp);
                maxi= max(value, maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1)));
        return f(0,0,c-1,r,c, grid, dp); 
    }
};

// tabulation-> top to bottom 
// Time Complexity: O(N*M*M)*9
// Space Complexity: O(N*M*M)
class Solution2 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        int dp[r][c][c];
        // base case
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                if(j1==j2)
                    dp[r-1][j1][j2] = grid[r-1][j1];
                else 
                    dp[r-1][j1][j2] = grid[r-1][j1]+ grid[r-1][j2];
            }
        }
        for(int i=r-2; i>=0; i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxi=0;
                    for(int dj1= -1; dj1<= +1 ; dj1++){
                        for(int dj2=-1; dj2<= +1;dj2++){
                            int value=0;
                            if(j1==j2) // at same position 
                                value = grid[i][j1];
                            else 
                                value = grid[i][j1]+ grid[i][j2];
                            // out of bound case 
                            if(j1+dj1>=0 && j1+dj1< c && j2+dj2>=0 && j2+dj2< c)
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else 
                                value+= -1e8;
                            maxi= max(value, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;      
                }
            }
        }
        return dp[0][0][c-1];
    }
};

//  space optimization 
// Time Complexity: O(N*M*M)*9
// Space Complexity: O(M*M)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        vector<vector<int>> prev(c, vector<int>(c,0));
        vector<vector<int>> curr(c, vector<int>(c,0));
        
        // base case
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                if(j1==j2)
                    prev[j1][j2] = grid[r-1][j1];
                else 
                    prev[j1][j2] = grid[r-1][j1]+ grid[r-1][j2];
            }
        }

        for(int i=r-2; i>=0; i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxi=INT_MIN;
                    for(int dj1= -1; dj1<= +1 ; dj1++){
                        for(int dj2=-1; dj2<= +1;dj2++){
                            int value=0;
                            if(j1==j2) // at same position 
                                value = grid[i][j1];
                            else 
                                value = grid[i][j1]+ grid[i][j2];
                            // out of bound case 
                            if(j1+dj1>=0 && j1+dj1< c && j2+dj2>=0 && j2+dj2< c)
                                value += prev[j1+dj1][j2+dj2];
                            else 
                                value+= -1e8;
                            maxi= max(value, maxi);
                        }
                    }
                    curr[j1][j2] = maxi;      
                }
            }
            prev= curr;
        }
        return prev[0][c-1];
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    int sum= sol.cherryPickup(grid);
    return sum;
    return 0;
}