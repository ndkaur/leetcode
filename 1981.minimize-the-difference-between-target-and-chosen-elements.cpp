/*
 * @lc app=leetcode id=1981 lang=cpp
 *
 * [1981] Minimize the Difference Between Target and Chosen Elements
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
    int f(int row, int sum, int target, vector<vector<int>>& mat, vector<vector<int>>& dp){
        int n = mat.size();
        int m = mat[0].size();

        if(row==n){
            return abs(target-sum);
        }

        if(dp[row][sum]!=-1)
            return dp[row][sum];
        
        int mn = INT_MAX;
        // row we know , go in each row's column
        for(int col=0; col<m; col++){
            mn = min(mn, f(row+1, sum+mat[row][col], target, mat, dp));
        }
        return dp[row][sum] = mn;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        // dp-> sum, row
        vector<vector<int>> dp(n, vector<int>(5001, -1));
        // row and sum change matters to us
        return f(0, 0, target, mat, dp);
    }
};

// @lc code=end


int main(){

    return 0;
}