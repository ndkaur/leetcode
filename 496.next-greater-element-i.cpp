/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
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
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> help;
        vector<int> out;
        map<int,int> ans;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!help.empty() && help.back()<=nums2[i]){
                help.pop_back();
            }
            if(help.empty()){
                ans[nums2[i]]= -1;
            }
            else{
                ans[nums2[i]]= help.back();
            }
            
            help.push_back(nums2[i]);
        }

        for(auto x:nums1){
            out.push_back(ans[x]);
        }
        return out;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums1={4,1,2};
    vector<int> nums2={1,3,4,2};
    vector<int> out=sol.nextGreaterElement(nums1,nums2);
    print(out);
    return 0;
}