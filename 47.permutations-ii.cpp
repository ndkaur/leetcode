/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
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
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        permute(nums,ans,0);
        return ans;
    }
    void permute(vector<int> &nums,vector<vector<int>> & ans,int idx){
        int n=nums.size();
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            //for dublicates
            if(i!=idx && nums[i]==nums[idx])
                continue;
            swap(nums[i],nums[idx]);
            permute(nums,ans,idx+1);
        }
        for(int i=n-1;i>idx;i--)
            swap(nums[i],nums[idx]);
        
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        f(0, nums, ans);
        return ans;
    }
    void f(int idx,vector<int> nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            if(i!=idx && nums[i]==nums[idx])
                continue;
            swap(nums[idx], nums[i]);
            f(idx+1, nums, ans);
            // swap(nums[idx], nums[i]);
        }
    }
};

class Solution0 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        f(0, nums, ans);
        return ans;
    }
    void f(int idx,vector<int> nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<n; i++){
            if(i!=idx && nums[i]==nums[idx])
                continue;
            swap(nums[idx], nums[i]);
            f(idx+1, nums, ans);
            // swap(nums[idx], nums[i]);
        }
    }
};

class Solution { //O(N!)  space-> O(N! * N)
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(n,0);
        f(nums, ans, temp, freq);
        return ans;
    }
    void f(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, vector<int>& freq){
        int n = nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(freq[i] || (i>0 && nums[i]==nums[i-1]) && !freq[i-1])
                continue;
            freq[i] = 1;
            temp.push_back(nums[i]);
            f(nums, ans, temp, freq);
            freq[i] = 0;
            temp.pop_back();
        }
    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<int> nums={1,1,2,2};
    vector<vector<int>> ans=sol.permuteUnique(nums);
    for(auto x:ans){
        print(x);
    }
    return 0;
}
