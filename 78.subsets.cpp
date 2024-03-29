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

// recursive
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, nums, temp, ans);
        return ans;
    }
    void f(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        int n= nums.size();
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        f(idx+1, nums, temp, ans);
        temp.pop_back();
        f(idx+1, nums, temp, ans);
    }
};


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



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};



// 1 2 3
// vvi  ans = { {} }
// num = 1 
// arrays = {{}}
// temp = {1} 
// ans = {} ,{1}
// .................
// num =2 
// arrays = {}, {1}
// temp = {2} ,{1,2}
// ans= {},{1},{2},{1,2}
// .................
// num =3 
// arrays = {} {1} {2} {1,2} 
// temp = {3},{1,3} {2,3} {1,2,3}
// ans = {} {1} {2} {1,2} {3} {1,3} {2,3} {1,2,3}


// O(2^n * n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // i< 2^n -1
        int p = 1<<n;
        vector<vector<int>> ans(p);
        for(int i=0; i<p; i++){
            for(int  j=0; j<n; j++){
                // whatever bit is set add that number
                if(i & (1<<j)){
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
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