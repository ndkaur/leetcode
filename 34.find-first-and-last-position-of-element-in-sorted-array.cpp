/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
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

// so we use to binary search 
//  first search is for tho find the first num equla to target 
// second search is to find the last num equal to the target 


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        if(n==0) return {-1,-1};
        int left=-1;
        int right=n;
        while(1+left<right){
            int mid= left+(right-left)/2;
            // we have to find the first idx of elem to be equal so we gave = condition to right 
            if(target<=nums[mid]){
                right= mid;
            }
            else{
                left=mid;
            }
        }
        // if right not qual to target 
        if(right==n || nums[right]!= target)
            return {-1,-1};
        // if right equal to target then it is the first positon of target to occur 
        vector<int> ans={right};
        // start serach for last position 
        left=-1;
        right=n;
        while(1+left<right){
            int mid= left+(right-left)/2;
            // we need to find the last position so gave = condition to left 
            // left will keep on increasing till it doesnot reach last idx of target 
            if(nums[mid]<=target){
                left= mid;
            }
            else    
                right= mid;
        }
        // push the left idx as the last position
        ans.push_back(left);
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={5,7,7,8,8,10};
    int target= 8;
    vector<int> ans= sol.searchRange(nums, target);
    for(auto it:ans)
        cout<<it<<endl;
    return 0;
}