/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
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
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> extra=nums;
        sort(extra.begin(),extra.end());
        int i=0,j=n-1;
        while(i<n && nums[i]==extra[i])
             i++;
        while(j>=0 && nums[j]==extra[j])
             j--;
        if(i>j)
            return 0;
        else 
            return j-i+1;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> nums={2,6,4,8,10,9,15};
    int count=sol.findUnsortedSubarray(nums);
    cout<<count;
    return 0;
}