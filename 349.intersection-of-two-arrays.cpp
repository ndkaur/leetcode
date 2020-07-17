/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        set<int> none;
        for(auto x: nums1) none.insert(x);

        sort(nums2.begin(),nums2.end());
        
        for(auto ele: none){
            if(is_present(ele, nums2))
                out.push_back(ele);
        }

        return out;
    }

    bool is_present(int target, vi &nums2){
        int l=0 ,r=nums2.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums2[mid]==target)
                return true;
            else if(nums2[mid]<target){
                l=mid+1;
            }
            else{ 
                r=mid-1;
            }   
        }
        return false;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};
    vector<int> out=sol.intersection(nums1,nums2);
    print(out);
    return 0;
}