/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
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
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int row= dun.size();
        int col = dun[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        // filling the last end value
        dp[row-1][col-1] = dun[row-1][col-1] > 0 ? 1: 1-dun[row-1][col-1]; 
        // filling the last col 
        for(int i=row-2;i>=0;i--){
            dp[i][col-1] = max(dp[i+1][col-1]-dun[i][col-1] , 1);
        }    
        // filling the last row
        for(int j= col-2 ;j>=0;j--){
            dp[row-1][j] = max(dp[row-1][j+1] - dun[row-1][j] , 1); 
        }
        // filling the left area 
        for(int i= row-2;i>=0;i--){
            for(int j=col-2;j>=0;j--){
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dun[i][j],1);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> dun ={{-2,-3,3},{-5,-10,1},{10,30,-5}};
    int ans = sol.calculateMinimumHP(dun);
    cout<< ans;
   return 0;
}


// -2  -3   3
// -5  -10  1
// 10  30  -5

// dp = 

// 7   5   2
// 6   11   5    
// 1   1   6   

// last is filled by -> 1-(-5)=6 or 1( if the value is very much positive)
// filing last col ->  6-1= max(5,1)=5  , 5-3 = max(2,1)=2
// filing last row ->  6-30 = -24(very -ve val ) so max(-24,1)=1 ,
                    //  like wise 1 -10 = max(-9 ,1)=1
// filling the rest of the vacant spaces 
// min of the next right and the below value 
// to fill dp[1][1]  ->  max(min(1,5) - dun[1][1] , 1) = 1 -(-10) = 11   
// dp[1][0] = min(1,1)= 1-(-5) = 6
// dp[0][1] = min(11,2) = 2 -(-3) =5
// dp[0][0] = min(6,5) = 5 -(-2) = 7 