/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution0 {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const int MOD = 1e9+7;
        sort(nums.begin(), nums.end());

        vector<int> subcnt(n,1); // at each idx how many subseq are there 
        // no of subseq starting from i to j = 2^j-i 
        // eg = (1,2,3) = i=0, j=2  2^2 =4 , so its powers of 2 
        for(int i=1; i<n; i++){
            subcnt[i] = (subcnt[i-1]*2)%MOD;
        }

        int i = 0;
        int j = 0;
        int cnt = 0;

        while(i<n){
            while(j<n && nums[i]+nums[j]<=target){
                j++;
            }
            if(i<j){
                cnt = (cnt + subcnt[j-i-1])%MOD;
            }
            i++;
            j= i;
        }
        return cnt;
    }
};



class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const int MOD = 1e9+7;
        sort(nums.begin(), nums.end());

        vector<int> subcnt(n,1); // at each idx how many subseq are there 
        // no of subseq starting from i to j = 2^j-i 
        // eg = (1,2,3) = i=0, j=2  2^2 =4 , so its powers of 2 
        for(int i=1; i<n; i++){
            subcnt[i] = (subcnt[i-1]*2)%MOD;
        }

        int i = 0;
        int j = n-1;
        int cnt = 0;

        while(i<=j){
            if(nums[i]+nums[j]<=target){
                cnt = (cnt+ subcnt[j-i])%MOD;
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
    }7
    41
};

// no of subseq stating for i to j = 2^(j-i)
// total no of subseq bewtwwn i and j = 2^(j-i+1)-1 =>2^length - 1
// @lc code=end

