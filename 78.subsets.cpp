/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
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

//  Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int num:nums){
            vector<vector<int>> arrays= ans;
            for(vector<int> temp: arrays){
                temp.push_back(num);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

1 2 3
vvi  ans = { {} }
num = 1 
arrays = {{}}
temp = {1} 
ans = {} ,{1}
.................
num =2 
arrays = {}, {1}
temp = {2} ,{1,2}
ans= {},{1},{2},{1,2}
.................
num =3 
arrays = {} {1} {2} {1,2} 
temp = {3},{1,3} {2,3} {1,2,3}
ans = {} {1} {2} {1,2} {3} {1,3} {2,3} {1,2,3}

// @lc code=end


int main(){
    Solution sol;
    vector<int>nums={1,2,3};
    vector<vector<int>> result;
    result=sol.subsets(nums);
    for(auto x:result){
        print(x);
    }
    return 0;
}