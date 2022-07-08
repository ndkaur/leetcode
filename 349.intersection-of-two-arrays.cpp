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
class Solution0 {
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

class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ;
        unordered_set<int> check(nums1.begin(),nums1.end());
        for(auto x:nums2){
            if(check.count(x)){
                ans.push_back(x);
                check.erase(x);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        // print(nums1);
        // print(nums2);
        vector<int> ans;
        
        for(int i=0;i<nums1.size();i++){
            if(i-1>=0 && nums1[i-1]==nums1[i])
                continue;
        
            int left = -1;
            int right = nums2.size();
            int mid=0;
            int temp=0;

            while(1+left<right){
                mid= left+(right-left)/2;

                if(nums2[mid]<=nums1[i]){
                    left= mid;
                    temp= mid;
                }
                else
                    right= mid;
            }
            
            if(nums2[temp]==nums1[i])
                ans.push_back(nums2[temp]);
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    vector<int> out=sol.intersection(nums1,nums2);
    print(out);
    return 0;
}