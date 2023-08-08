/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

class Solution { //O(N)
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i]>nums[i+1]))
                return i;
        }
        return -1;
    }
};




class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    
            return 0;
        // if i=0 is the peak element then its right side will be decreasing order
        if(nums[0]>nums[1])
            return 0;
        // if i=n-1 is the peak then its left side will be increasing order
        if(nums[n-1]>nums[n-2])
            return n-1;
        int l = 1;
        int r = n-2;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]> nums[mid-1])
                l= mid+1;
            else 
                r = mid-1;
        }
        return -1;
    }
};



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int l= 0;
        int h= n-1;
        while(l<h){
            int mid= l+(h-l)/2;
            if(nums[mid]>nums[mid+1])
                h= mid;
            else 
                l=mid+1;
        }
        return l;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,1,3,5,6,4};
    int ans = sol.findPeakElement(nums);
    cout<<ans;
    return 0;
}