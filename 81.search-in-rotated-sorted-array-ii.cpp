/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
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
class Solution { //O(logN)
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
                return true;
            //check which half is sorted but all are equal
            if(nums[l]== nums[mid] && nums[mid]==nums[r]){
                l++;
                r--;
                continue;
            }
            // if left half is sorted
            if(nums[l]<=nums[mid]){
                // lies int he sorted left half
                if(nums[l]<=target && target<=nums[mid])
                    r = mid-1;
                else 
                    l = mid+1;
            }
            // right half is sorted
            else {
                // target lies in the right half
                if(nums[mid]<=target && target<=nums[r])
                    l = mid+1;
                else 
                    r = mid-1;
            }
        }
        return false;
    }
};
// @lc code=end


int main(){

    return 0;
}