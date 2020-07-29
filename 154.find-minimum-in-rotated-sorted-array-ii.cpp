/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
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
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
                l=mid+1;
            else if(nums[mid]<nums[r])
                r=mid;
            else if (nums[mid]==nums[r])
                r--;
        }
        return nums[l];
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> nums={4,5,5,6,7,7,1,1,2};
    int ans=sol.findMin(nums);
    cout<<ans;
    return 0;
}