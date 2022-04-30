/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
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
//  recursion  time -> exponential 
class Solution0 {
public:
    int f(int i, int j, vector<int>& nums){
        if(i>j) return 0;
        int mx=INT_MIN;
        for(int idx=i;idx<=j;idx++){
            int cost= nums[i-1]* nums[idx]* nums[j+1] + f(i,idx-1,nums)+ f(idx+1,j,nums);
            mx= max(mx, cost);
        }
        return mx;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return f(1,n,nums);
    }
};

//  memoization  time n^3   space N^2 + N
class Solution1 {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;
        int mx=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int idx=i;idx<=j;idx++){
            int cost= nums[i-1]* nums[idx]* nums[j+1] + f(i,idx-1,nums,dp)+ f(idx+1,j,nums,dp);
            mx= max(mx, cost);
        }
        return dp[i][j]= mx;
    }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
};

//  tabulation time n^3  space N^2
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);

        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int mx= INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    int cost= nums[i-1]* nums[idx]* nums[j+1] + dp[i][idx-1]+ dp[idx+1][j];
                    mx= max(mx, cost);
                }
                dp[i][j]= mx;
            }
        }

        return dp[1][n];
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={3,1,5,8};
    int ans= sol.maxCoins(nums);
    cout<<ans; 
    return 0;
}