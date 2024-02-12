/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
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


// time :- O(N*2N)  recursion 
class Solution0 {
public:
    vector<int> solve(int i, vector<int>& nums){
        int n= nums.size();
        vector<int> ans;
        if(i>=n) 
            return {};
        for(int j=i+1; j<n; j++){
            if(nums[j]%nums[i]==0){
                vector<int> temp = solve(j, nums);
                if(temp.size()> ans.size())
                    ans = temp;
            }
        }
        ans.push_back(nums[i]);
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<n; i++){
            vector<int> temp = solve(i, nums);
            if(temp.size()>ans.size()){
                ans = temp;
            }
        }
        return ans;
    }
};

// memoization 
class Solution1 { //O(N^3)
public:
    vector<int> solve(int i, vector<int>& nums, unordered_map<int,vector<int>>& dp){
        int n= nums.size();
       
        if(i>=n) 
            return {};

        if(dp.count(i))
            return dp[i];

        for(int j=i+1; j<n; j++){
            if(nums[j]%nums[i]==0){
                vector<int> temp = solve(j, nums, dp);
                if(temp.size()>= dp[i].size())
                    dp[i] = temp;
            }
        }
        dp[i].push_back(nums[i]);
        return dp[i];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        unordered_map<int,vector<int>> dp;

        for(int i=0; i<n; i++){
            vector<int> temp = solve(i, nums, dp);
            if(temp.size()>ans.size()){
                ans = temp;
            }
        }
        return ans;
    }
};

class Solution { //O(N^2)
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        // if a greetaer number is divisible by smaller number then its divisible by all smaller numbers 
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        
        int mx = 1;
        int lastidx = 0;

        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                // 2%1= 0
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){ // size changed 
                    dp[i] = 1+dp[j];
                    hash[i]= j;// idx stored
                }
            }
            if(dp[i]>mx){
                mx = dp[i];
                lastidx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastidx]);

        while(hash[lastidx]!=lastidx){
            lastidx = hash[lastidx];
            temp.push_back(nums[lastidx]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};



// @lc code=end


int main(){ 
    Solution sol;
    vector<int> nums={1,2,3};
    vector<int> ans= sol.largestDivisibleSubset(nums);
    print(ans);
    return 0;
}