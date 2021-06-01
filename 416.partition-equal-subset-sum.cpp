/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    vector<vector<int>> dp;
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }
        if(sum & 1)
            return false;
        dp.clear();
        dp.resize(n+1,vector<int>(sum/2+1,-1));
        return subsum(nums,n,0,sum/2);
    }
    bool subsum(vector<int>& nums, int n , int pos, int sum){
        if(sum==0) 
            return true;
        else if(pos>=n || sum<0) 
            return false;
        if(dp[pos][sum]!=-1)
            return dp[pos][sum];
        return dp[pos][sum]=subsum(nums,n,pos+1,sum-nums[pos]) || subsum(nums,n,pos+1,sum);
        //include || not include 
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={2,2,3,5};
    bool ans =sol.canPartition(nums);
    cout<<ans;
    return 0;
}