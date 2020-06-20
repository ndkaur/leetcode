/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cur_len = 1;
        if(n==0)
            return 0;
        for(int i=1; i<n; ++i){
            if(nums[i-1]<nums[i]){
                ++cur_len;
            }else{
                ans = max(ans,cur_len);
                cur_len = 1;
            }
        }
        return max(ans,cur_len);
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,3,5,4,7};
    int count=sol.findLengthOfLCIS(nums);
    cout<<count;
    return 0;
}