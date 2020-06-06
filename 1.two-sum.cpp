/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> out;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        map<int,int> seen;
        for(int i=0; i<n; ++i){
            int req = target - nums[i];
            if(seen.count(req)){
                return {seen[req], i};
            }

            seen[nums[i]] = i;
        }

        return {-1,-1};
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int>nums={2,7,11,15};
    int target;
    vector<int> out=sol.twoSum(nums,9);
    print(out);
    return 0;
}