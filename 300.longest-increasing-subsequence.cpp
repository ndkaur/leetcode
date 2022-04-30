/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
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
class Solution0 {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> list(n);
        list[0]=1;
        for(int i=1;i<n;i++){
            list[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && list[i]<list[j]+1)
                    list[i]=list[j]+1;
            }
        }
        return *max_element(list.begin(),list.end());
    } // O(n2)
};

//binary search log(n)
//travelsal of array O(n)

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> seq;
        seq.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(seq.back() < nums[i])
                seq.push_back(nums[i]);
            else { 
                // binary search for finding location 
                int idx = lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
                seq[idx]=nums[i];
            }
        }
        return seq.size();
    }
};

// dp 
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n);
        int maax=0;
        for(int i=0;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]>mx)
                        mx=dp[j];
                }
            }
            dp[i]= mx+1;
            if(dp[i]>maax)
                maax=dp[i];
        }
        return maax;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> dp;
        for(auto x: nums){
            auto it = lower_bound(dp.begin(),dp.end(),x);
            // lower bound check if greter or equal 
            // coming element can find someone greater than it -> replace it 
            //  if all elements are smaller then exisiting ones ->pushback
            if(it==dp.end())
                dp.push_back(x);
            else 
                *it=x;
        }
        return dp.size();
    }
};


// @lc code=end

// recursion time 2^n  space O(n)
class Solution {
public:
    int f(int idx, int prev_idx, vector<int>& nums){
        int n= nums.size();
        if(idx==n) return 0;
        int len= f(idx+1,prev_idx,nums); // not take 
        if(prev_idx== -1 || nums[idx]> nums[prev_idx]) // take 
            len = max(len,1+f(idx+1,idx,nums));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return f(0,-1, nums);
    }
};


//  memoization  time -> O(n*n)  space-> O(n*n)+O(n)
class Solution {
public:
    int f(int idx, int prev_idx, vector<int>& nums,vector<vector<int>>& dp){
        int n= nums.size();
        if(idx==n) return 0;

        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1]; // prev+1 so that -1 idx becomes 0

        int len= f(idx+1,prev_idx,nums,dp); //not take 

        if(prev_idx== -1 || nums[idx]> nums[prev_idx])
            len = max(len,1+f(idx+1,idx,nums,dp));
            
        return dp[idx][prev_idx+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1)); // prev+1 to change the index of -1 to 0 
        return f(0,-1, nums,dp);
    }
};

// tabulation  // while conversion the second parameter goes into +1 state
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));  // n+1 so each idx shift with +1

        for(int idx=n-1; idx>=0; idx--){
            for(int prev_idx= idx-1; prev_idx>= -1; prev_idx--){

                int len = dp[idx+1][prev_idx+1]; // not take 

                if(prev_idx ==-1 || nums[idx]>nums[prev_idx] )
                    len = max(len, 1+dp[idx+1][idx+1]); // take

                dp[idx][prev_idx+1]= len;
            }
        }

        return dp[0][-1+1];
    }
};

//  space optimization   time ->o(n*n)  space -> o(n) *2 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> next(n+1,0);
        vector<int> cur(n+1,0);
        
        for(int idx=n-1; idx>=0; idx--){
            for(int prev_idx= idx-1; prev_idx>= -1; prev_idx--){

                int len = next[prev_idx+1]; // not take 

                if(prev_idx ==-1 || nums[idx]>nums[prev_idx] )
                    len = max(len, 1+next[idx+1]); // take

                cur[prev_idx+1]= len;
            }
            next= cur;
        }

        return next[-1+1];
    }
};


//  1-D DP  time -> O(n*n)  space O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        int mx=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]< nums[i]){
                    dp[i]= max(dp[i], 1+dp[prev]);
                }
            }
            mx= max(mx, dp[i]);
        }
        return mx;
    }
};

//  to print the lis

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int mx=1;
        int lastIdx=0;
        for(int i=0;i<n;i++){
            hash[i]=i; // every indx is marked with its own idx at first 
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]> dp[i]){
                    dp[i]= 1+dp[prev];
                    hash[i]= prev;
                }
            }
            if(dp[i]> mx){
                mx= dp[i];
                lastIdx= i; // the idx at which we found the mx length 
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIdx]);
        while(hash[lastIdx]!= lastIdx){
            lastIdx = hash[lastIdx];
            temp.push_back(arr[lastIdx]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};


//  BINARY SEARCH :- we dont print the lis here , so the sequence doesnt matter. 
//  we take nos in increasing order and replace when we found someone better 
class Solution {   //time - O(n* logN)  space O(n)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]> temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{ // binary search 
                int idx= lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
                temp[idx]= nums[i];
            } // replace the element 
        }
        return len;
    } // lower bound gives te index of the element that we want to find or the exact next greater elemt 
};


int main(){
    Solution sol;
    vector<int> nums={10,9,2,5,3,7,101,18};
    int ans=sol.lengthOfLIS(nums);
    cout<<ans;
    return 0;
}