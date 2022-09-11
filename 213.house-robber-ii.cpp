/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
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

//  same as qno 198 - house robber 1;
//  so we will divide arr in two parts , one will exclude first element 
//  second array will exclude last element 
class Solution {
public:
    int rob(vector<int>& nums) {
       int n =nums.size();
       if(nums.empty()) return 0;
       if(n==1) return nums[0];

       vector<int> numsA(nums.begin(),nums.end()-1);
       vector<int> numsB(nums.begin()+1,nums.end());

       return max(rb(numsA),rb(numsB)); 
    }
    int rb(vector<int>&nums){
        int a=0,b=0,res=0;

        for(int i=0;i<nums.size();i++){
            res=max(a+nums[i],b);
            a=b;
            b=res;
        }
        return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        vector<int> f, s;
        for(int i=0; i<n ;i++){
            if(i!=0){
                f.push_back(nums[i]);
            }
            if(i!=n-1)
                s.push_back(nums[i]);
        }
        return max(house(f), house(s));
    }
    int house(vector<int>& arr){
        int n= arr.size();
        vector<int> dp(n,0);
        dp[0] = arr[0];
        for(int i=1; i<n; i++){
            int take = arr[i];
            if(i>1)
                take += dp[i-2];
            int ntake = dp[i-1];
            dp[i] = max(take, ntake);
        }
        return dp[n-1];
    }
};

//  space optimization solution 
class Solution {
public:
    int robber(vector<int>& num){
        int n= num.size();
        int prev2=0;
        int prev=num[0];
        int curr;
        for(int i=1;i<n;i++){
            int pick = num[i];
            if(i>1) pick+= prev2;
            int notpick = 0+ prev;
            curr= max(pick, notpick);
            prev2= prev;
            prev= curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);//leave first add rest
            if(i!=n-1) temp2.push_back(nums[i]); // leave last add rest
        }
        return max(robber(temp1), robber(temp2));
    }
}; 
// @lc code=end

class Solution {
public:
    int rob(vector<int>& nums){
        int n= nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp(n);
                   // remove last ele         // remove fisrt ele 
        return max(solve(0, n-2, nums, dp) , solve(1, n-1, nums, dp));
    }
    int solve(int first, int last, vector<int>& nums, vector<int>& dp){
        dp[first] = nums[first];
        dp[first+1] = max(nums[first],nums[first+1]);
        
        for(int i=first+2; i<=last; i++){
            int prev = dp[i-1];
            int prevv = nums[i] + dp[i-2];
            dp[i] = max(prev, prevv);
        }
        return dp[last];
    }
};


int main(){
    Solution sol;
    vector<int> nums={1,2,3,1};
    int ans=sol.rob(nums);
    cout<<ans;
    return 0;
}