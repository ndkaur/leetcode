/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
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
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(auto num:nums){
                if(num<=i)
                    dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<=target;i++){
            if(!dp[i]) 
                continue;
            for(int num:nums){
                if(num+i<=target)
                    dp[i+num] += dp[i];
            }
        }
        return dp[target];
    }
};

//  recursion tle
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        return f(nums, target, 0, n);
    }
    int f(vector<int>& nums, int target, int idx, int n){
        if(target<0) return 0;
        if(target==0) return 1;
        int count=0;
        for(int i=0;i<n;i++){
            // inifinte supply of idx can pick many times
            count+= f(nums, target-nums[i], idx, n);
        }
        return count;
    }
};

//  memoization
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<int> dp(target+1, -1);
        return f(nums, target, 0, n ,dp);
    }
    int f(vector<int>& nums, int target, int idx, int n, vector<int>& dp){
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];

        int count=0;
        for(int i=0;i<n;i++){
            count+= f(nums, target-nums[i], idx, n,dp);
        }
        dp[target]=count;
        return count;
    }
};

// tabulation 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n= nums.size();
        vector<int> dp(target+1, 0);
        dp[0]=1; // target=0
        for(int i=1;i<=target;i++){
            for(int j=0;j<n;j++){
                // target-nums[idx]
                if(i-nums[j]>=0) // if target<0
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3};
    int target = 4;
    int ans =sol.combinationSum4(nums,target);
    cout<<ans;
    return 0;
}