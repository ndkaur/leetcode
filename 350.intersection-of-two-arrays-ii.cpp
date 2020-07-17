/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> out;
        sort(nums1.begin(),nums1.end());

        for(int i=0;i<n;i++){ // target is from nums2
            int l=0,r=nums1.size()-1;
            
            while(l<=r){ // binary search is on nums1
                int mid=l+(r-l)/2; 
                if(nums1[mid]==nums2[i]){
                    out.push_back(nums1[mid]);
                    nums1.erase(nums1.begin()+mid);
                    break;
                }
                else if(nums1[mid]>nums2[i])
                    r=mid-1;
                else 
                    l=mid+1;
            }
        }
        return out;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    vector<int> out=sol.intersect(nums1,nums2);
    print(out);
    return 0;
}