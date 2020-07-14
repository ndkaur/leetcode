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

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> out = {{}};
        for(int x: nums){
            vector<vector<int>> cur = out;
            for(auto &c: cur){
                c.push_back(x);
                out.push_back(c);
            }
        }
        return out;
    }
};
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