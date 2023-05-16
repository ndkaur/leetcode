/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = n-1;
        int mod = 1e9+7;
        int ans =0;
        vector<int> pow(n);
        pow[0]=1;
        for(int i=1; i<n; i++){
            pow[i] = (pow[i-1]*2)%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]>target)
                r--;
            else{
                ans = (ans+ pow[r-l]) % mod;
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end

