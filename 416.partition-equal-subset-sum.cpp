/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
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


//  recursion  t-> expo  s->o(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int num:nums)
            sum+=num;
        int target= sum/2;
        if(sum%2)
            return false;
        return f(n-1, target, nums);
    }
    int f(int idx, int target, vector<int>& nums){
        if(target==0) return true;
        // constarints starting from 1 so num[idx] can never be 0
        if(idx==0)
            return (nums[0]==target);
        
        bool notTake= f(idx-1, target, nums);
        bool take= false;
        if(nums[idx]<=target)
            take= f(idx-1,target-nums[idx], nums);
        return notTake | take;
    }
};

//  memo -> t-> O(n* target) sc->O(n* target)+ O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int num:nums)
            sum+=num;

        if(sum%2)
            return false;
        else {
            int target= sum/2;
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            return f(n-1, target, nums,dp);
        }
    }
    int f(int idx, int target, vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        
        if(idx==0)
            return (nums[0]==target);
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        bool notTake= f(idx-1, target, nums,dp);
        bool take= false;
        if(nums[idx]<=target)
            take=f(idx-1,target-nums[idx], nums,dp);
        return dp[idx][target] = notTake || take;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int num:nums)
            sum+=num;

        if(sum%2==1)
            return false;
        else {
            int target= sum/2;
            vector<vector<bool>> dp(n,vector<bool>(target+1,false));

            for(int i=0;i<n;i++)
                dp[i][0]= true;

            if(nums[0]<= target)
                dp[0][nums[0]]= true;

            for(int i=1;i<n;i++){
                for(int j=1; j<=target; j++){
                    bool notTake= dp[i-1][j];
                    bool take= false;
                    if(nums[i]<=j)
                        take= dp[i-1][j-nums[i]];
                    dp[i][j] = notTake || take;
                }
            }
            return dp[n-1][target];
        }
    }
};



// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,2,3,5};
    bool ans =sol.canPartition(nums);
    cout<<ans;
    return 0;
}