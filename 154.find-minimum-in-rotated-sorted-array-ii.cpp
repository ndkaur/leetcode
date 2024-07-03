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



class Solution { // O(logN)
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int mn =  INT_MAX;
        
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[l]==nums[mid] && nums[mid]==nums[h]){
                mn = min(mn, nums[mid]);
                l++;
                h--;
                continue;
            }
            if(nums[l]<=nums[mid]){
                mn = min(mn, nums[l]);
                l= mid+1;
            }
            else{
                mn = min(mn, nums[mid]);
                h=mid-1;
            }
        }
        return mn;
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