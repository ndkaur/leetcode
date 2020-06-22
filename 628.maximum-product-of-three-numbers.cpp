/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
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
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums.back(),
                   nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,5,6,4,2};
    int product=sol.maximumProduct(nums);
    cout<<product;
    return 0;
}