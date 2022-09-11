/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
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
class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int a =0,b=0,res=0;
        for(int i=0 ;i<n;i++){
            res =  max(a+nums[i],b);
            a=b;
            b=res;
        }
        return res;
    }
};

// RECURSION - Time limit exceeded 
class Solution {
public:
    int fun(int idx , vector<int>& nums){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        int pick = nums[idx]+ fun(idx-2, nums);
        int notPick= 0+ fun(idx-1, nums);
        return max(pick,notPick);
        
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        return fun(n-1,nums);
    }
};


//  Memoization - top down approach 
class Solution {
public:
    int fun(int idx , vector<int>& nums, vector<int>& dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int pick = nums[idx]+ fun(idx-2, nums,dp);
        int notPick= 0+ fun(idx-1, nums,dp);
        return dp[idx]=max(pick,notPick);
        
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        return fun(n-1, nums,dp);
    }
};


//  tabulation - bottom up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i-2>=0)
                take +=  dp[i-2];
            int ntake= dp[i-1];
            dp[i] = max(take, ntake);
        }
        return dp[n-1];
    }
};

//  space optimization 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int prev2= 0;
        int prev= nums[0];
        int curr;
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick+= prev2;
            int notpick= 0+ prev;
            curr= max(pick,notpick);
            prev2= prev;
            prev= curr;
        }
        return prev;
        
    }
};
// @lc code=end

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return nums[0];
        if(n==2) 
            return max(nums[0], nums[1]);
        // make same dp as size of num 
        // aply simple logic 
        // can pick prev1 or prev2
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            // prev2 prev1 num[i]
            int prev1= dp[i-1];
            int prev2 = nums[i] + dp[i-2];
            dp[i] = max(prev1, prev2);
        }
        return dp[n-1];
    }
};


int main(){
    Solution sol;
    vector<int> nums={2,7,9,3,1};
    int ans = sol.rob(nums);
    cout<<ans;
    return 0;

}