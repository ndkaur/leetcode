/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
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
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]+nums[r]==target){
                out.push_back(l+1);// zero based indexing so +1
                out.push_back(r+1);
                return out;
            }
            else if(nums[l]+nums[r]>target)
                r--;
            else 
                l++;
        }
        return out;
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> out=sol.twoSum(nums,target);
    print(out);
    return 0;
}