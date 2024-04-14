/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mxarray= INT_MIN;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=i;j<n;j++){
                curr += nums[j];
                mxarray =  max(mxarray , curr);
            }
        }
        return mxarray;
    }
};

class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur_arry= nums[0];
        int max_arry= nums[0];
        for(int i=1;i<n;i++){
            int num = nums[i];
            cur_arry = max(num, cur_arry+num);
            max_arry =  max(max_arry , cur_arry);
        }
        return max_arry;
    }
};


class Solution1 {
public:
    int solve(int idx, vector<int>& nums, bool canPick, vector<vector<int>>& dp){
        int n = nums.size();
        if(idx>=n)
            return canPick ? 0 : -1e5;
        if(dp[idx][canPick]!=-1)
            return dp[idx][canPick];
        if(canPick){
            return dp[idx][canPick] = max(0, nums[idx]+solve(idx+1, nums, true, dp));
        }
        return dp[idx][canPick] = max(solve(idx+1, nums, false, dp), nums[idx]+ solve(idx+1, nums,true, dp));
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0, nums, false, dp);
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums)));
        dp[0][0] = dp[1][0] = nums[0];
        for(int i = 1; i < size(nums); i++) {
            dp[1][i] = max(nums[i], nums[i] + dp[1][i-1]);
            dp[0][i] = max(dp[0][i-1], dp[1][i]);
        }
        return dp[0].back();
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        int mx= dp[0];
        for(int i=1;i<n;i++){
            dp[i] = nums[i]+ (dp[i-1]>0 ? dp[i-1]:0);
            mx= max(mx,dp[i]);
        }
        return mx;
    }
};

// kaden algo 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur =0;
        int mx =INT_MIN;
        for(int i=0; i<n; i++){
            cur += nums[i];
            if(mx < cur)
                mx = cur;
            if(cur<0)
                cur =0;
        }
        return mx;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    int ans= sol.maxSubArray(nums);
    cout<<ans;
    return 0;
}