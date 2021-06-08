/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
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
    int count=0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        cal(nums,target,0,0);
        return count;
    }
    void cal(vector<int>&nums,int target , int i, int sum){
        int n= nums.size();
        if(i==n){
            if(sum==target)
                count++;
        }
        else{
            cal(nums,target,i+1,sum+nums[i]);
            cal(nums,target,i+1,sum-nums[i]);
        }
    }
};

class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(int num:nums)
            sum+=num;
        if(sum<target || (sum+target)%2 !=0)
            return 0;
        int s= (target+sum)/2;
        vector<vector<int>> dp(n,vector<int>(s+1,0));
        dp[0][0] = nums[0] == 0 ? 2:1;
        for(int i=1;i<=s;i++)
            dp[0][i] = nums[0] == i ? 1:0;

        for(int i=1;i<n;i++){
            for(int j=0;j<=s;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i]<=j)
                    dp[i][j] += dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][s];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(int num:nums)
            sum+=num;
        if(sum<target || (sum+target)%2 !=0)
            return 0;
        int s= (target+sum)/2;
        vector<int> dp(s+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=s;j>=nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[s];
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums ={1,1,1,1,1};
    int target = 3;
    int ans = sol.findTargetSumWays(nums,target);
    cout<<ans;
    return 0;
}
