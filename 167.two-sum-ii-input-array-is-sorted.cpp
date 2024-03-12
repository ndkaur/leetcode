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


class Solution0 { // space O(n)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int  n = nums.size();
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int req = target- nums[i];
            if(mp.find(req)!=mp.end()){
                return {mp[req]+1, i+1};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};

// binary search 
class Solution1 {  // O(nlogn)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int  n = nums.size();
        for(int i=0; i<n; i++){
            int l = i+1;
            int h = n-1;
            while(l<=h){
                int mid = l+(h-l)/2;
                if(nums[mid]==target-nums[i]){
                    return  {i+1, mid+1};
                }
                else if(nums[mid]> target-nums[i]){
                    h = mid-1;
                }
                else 
                    l = mid+1;
            }
        }
        return {-1,-1};
    }
};


// two ptr
class Solution { 
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int  n = nums.size();
        int i =0;
        int j = n-1;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else {
                return {i+1, j+1};
            }
        }
        return {-1,-1};
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