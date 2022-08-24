/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
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


class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target){
        int n=nums.size();
        int i=0;
        for(i=0;i<n;i++){
            if(nums[i]>=target){
                break;
            }
        }
        return i;
    }
};
// @lc code=end
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target){
        int n=nums.size();
        if(n==0)
            return -1;
        int l=0,r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        return l;
        
    }
};


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        int l= -1;
        int r= n;
        while(1+l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(target < nums[mid])
                r= mid;
            else 
                l= mid;
        }
        return r;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,3,5,6};
    int target=7;
    int found=sol.searchInsert(nums,target);
    cout<<found;
    return 0;
}