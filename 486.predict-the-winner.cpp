/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
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
class Solution0 {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, nums,dp)>=0; // if in the end the final score is +ve
    }
    int f(int start, int end, vector<int>& nums, vector<vector<int>>& dp){
        if(dp[start][end]!=-1)
            return dp[start][end];
        if(start == end) // len =1 or reached same point 
            return nums[start];

        int pickstart = nums[start] - f(start+1, end, nums, dp);
        int pickend =  nums[end] - f(start, end-1, nums, dp);
        dp[start][end] = max(pickstart, pickend);
        return dp[start][end];
    }
};
// player 1 turn -> nums + (start+1 , end)  or nums + (start, end-1)
// player 2 turn -> -nums[i] + () // -ve cause we want the player 1 to win 

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, 0, nums,dp)>=0; // if in the end the final score is +ve
        
    }
    int f(int start, int end,int len, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(start == n || end == -1)
            return 0;
        if(start>end)
            return 0;
        
        if(dp[start][end]!=-1)
            return dp[start][end];

        int ans =0;

        if(len%2==0){ // even so player 1
            return dp[start][end] = max(nums[start] + f(start+1, end, len+1, nums, dp),
                                        nums[end] + f(start, end-1, len+1, nums, dp));
        }
        else{
            return dp[start][end] =  min(-nums[start] + f(start+1, end, len+1, nums, dp),
                                    -nums[end] + f(start, end-1, len+1, nums, dp));
        }
    }
};
// @lc code=end


int main(){

    return 0;
}