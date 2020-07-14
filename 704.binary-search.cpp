/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
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
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums.size()==0)
            return -1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else 
                r=mid-1;
        }
        return -1;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={-1,0,3};
    int target=9;
    int ans=sol.search(nums,target);
    cout<<ans;
    return 0;
}