/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far = nums[0];
        for(int i=1; i<n; i++){
            far--;
            if(far<0)
                return false;
            if(far<nums[i]){
                far = nums[i];
            }
        }
        return true;
    }
};

class Solution1 { // exponential 
public:
    bool find(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx==n-1)
            return true;
        if(nums[idx]==0)
            return false;
        
        int far = nums[idx]+idx;

        for(int jump=idx+1; jump<=far; jump++){
            if(find(jump, nums))
                return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return find(0, nums);
    }
};


class Solution2 {  //O(N*N)
public:
    bool find(int idx, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(idx==n-1)
            return true;

        if(nums[idx]==0)
            return false;

        if(dp[idx]!=-1)
            return dp[idx];

        int far = nums[idx]+idx;

        for(int jump=idx+1; jump<=far; jump++){
            if(find(jump, nums, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find(0, nums, dp);
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far = 0;

        for(int idx=0; idx<n; idx++){
            if(far < idx)
                return false;
            far = max(far, idx+nums[idx]);
        }
        return true;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,3,1,1,4};
    bool ans= sol.canJump(nums);
    cout<<ans;
    return 0;
}