/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
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
// class Solution0 {
//     int count=0;
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         cal(nums,target,0,0);
//         return count;
//     }
//     void cal(vector<int>&nums,int target , int i, int sum){
//         int n= nums.size();
//         if(i==n){
//             if(sum==target)
//                 count++;
//         }
//         else{
//             cal(nums,target,i+1,sum+nums[i]);
//             cal(nums,target,i+1,sum-nums[i]);
//         }
//     }
// };

// class Solution1 {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum=0;
//         for(int num:nums)
//             sum+=num;
//         if(sum<target || (sum+target)%2 !=0)
//             return 0;
//         int s= (target+sum)/2;
//         vector<vector<int>> dp(n,vector<int>(s+1,0));
//         dp[0][0] = nums[0] == 0 ? 2:1;
//         for(int i=1;i<=s;i++)
//             dp[0][i] = nums[0] == i ? 1:0;

//         for(int i=1;i<n;i++){
//             for(int j=0;j<=s;j++){
//                 dp[i][j] = dp[i-1][j];
//                 if(nums[i]<=j)
//                     dp[i][j] += dp[i-1][j-nums[i]];
//             }
//         }
//         return dp[n-1][s];
//     }
// };

// class Solution3 {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum=0;
//         for(int num:nums)
//             sum+=num;
//         if(sum<target || (sum+target)%2 !=0)
//             return 0;
//         int s= (target+sum)/2;
//         vector<int> dp(s+1,0);
//         dp[0]=1;
//         for(int i=0;i<n;i++){
//             for(int j=s;j>=nums[i];j--){
//                 dp[j] += dp[j-nums[i]];
//             }
//         }
//         return dp[s];
//     }
// };

// RECURSION
class Solution0 {
public:
    int f(int idx, int target, vector<int>& nums){
        int n= nums.size();
        if(idx==0){ 
            if(target==0 && nums[0]==0) 
                return 2;
            if(target==0 || target==nums[0])
                return 1;
            return 0;
        }
        int notPick= f(idx-1, target, nums);
        int pick=0;
        if(nums[idx]<=target)
            pick = f(idx-1,target-nums[idx], nums);
        return pick + notPick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int tsum=0;
        for(auto &it: nums) tsum+=it;
        // s1+s2= tsum  s1=tsum-s2  s1-s2= target    tsum-s2-s2 = target    tsum-2*s2= target   s2= (tsum-target )/2
        int s2= (tsum-target)/2;
        if(tsum-target< 0) return 0;
        if((tsum-target)%2==1) return 0;
        return f(n-1,s2, nums);
    }
};

//  MEMOIZATION
class Solution1 {
public:
    int f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        //  constraints starting from 0 so it is possible that num[idx] can be 0
        if(idx==0){ 
            if(target==0 && nums[0]==0)  // take + not take = 1+1=2
                return 2;
            if(target==0 || target==nums[0])
                return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notPick= f(idx-1, target, nums,dp);
        int pick=0;
        if(nums[idx]<=target)
            pick = f(idx-1,target-nums[idx], nums,dp);
        return dp[idx][target]= pick + notPick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int tsum=0;
        for(int i=0;i<n;i++) tsum+=nums[i];
        // s1+s2= tsum  s1=tsum-s2  s1-s2= target    tsum-s2-s2 = target    tsum-2*s2= target   s2= (tsum-target )/2
        
        if(tsum-target< 0) return 0;
        if((tsum-target)%2==1) return 0;

        int s2= (tsum-target )/2;
        vector<vector<int>> dp(n, vector<int>(s2+1,-1));
        return f(n-1,s2, nums,dp);
    }
};

// TABULATION
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int tsum=0;
        for(int i=0;i<n;i++) tsum+=nums[i];
        // s1+s2= tsum  s1=tsum-s2  s1-s2= target    tsum-s2-s2 = target    tsum-2*s2= target   s2= (tsum-target )/2
        
        if(tsum-target< 0) return 0;
        if((tsum-target)%2==1) return 0;

        int s2= (tsum-target )/2;
        vector<vector<int>> dp(n, vector<int>(s2+1,0));

        if(nums[0]==0) dp[0][0]=2; 
        else dp[0][0]=1;

        if(nums[0]!=0 && nums[0]<=s2) 
            dp[0][nums[0]]=1; 
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=s2;t++){
                int notPick= dp[i-1][t];
                int pick=0;
                if(nums[i]<=t){
                    pick= dp[i-1][t-nums[i]];
                }
                dp[i][t] = notPick+pick;
            }
        }
        return dp[n-1][s2];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int tsum=0;
        for(int i=0;i<n;i++) tsum+=nums[i];
        // s1+s2= tsum  s1=tsum-s2  s1-s2= target    tsum-s2-s2 = target    tsum-2*s2= target   s2= (tsum-target )/2
        int s2= (tsum-target )/2;
        vector<int> prev(s2+1,0);
        vector<int> curr(s2+1,0);
        
        if(tsum-target< 0) return 0;
        if((tsum-target)%2==1) return 0;

        
        if(nums[0]==0) prev[0]=2;   
        else prev[0]=1;

        if(nums[0]!=0 && nums[0]<=s2) 
            prev[nums[0]]=1; 
        
        for(int i=1;i<n;i++){
            for(int t=0;t<=s2;t++){
                int notPick= prev[t];
                int pick=0;
                if(nums[i]<=t){
                    pick= prev[t-nums[i]];
                }
                curr[t] = notPick+pick;
            }
            prev= curr;
        }
        return prev[s2];
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
