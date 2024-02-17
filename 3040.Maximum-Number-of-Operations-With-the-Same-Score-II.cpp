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


class Solution {
public:
    int solve(int l,int r,int score,vector<int>&nums, vector<vector<int>>& dp){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        
        int ans=0;
        //  first 2 nums == sum
        if(nums[l]+nums[l+1]==score)
            ans=max(ans, 1+solve(l+2,r,score,nums, dp));

        // last two nums == sum
        if(nums[r]+nums[r-1]==score)
            ans=max(ans, 1+solve(l,r-2,score,nums, dp));

        // first num + last num == sum
        if(nums[l]+nums[r]==score)
            ans=max(ans,1+solve(l+1,r-1,score,nums, dp));
        
        return dp[l][r]=ans;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int ans=0;

        // first two nums then i =2, j=n-1 , sum , num, dp
        ans=max(ans,1+solve(2,n-1,nums[0]+nums[1],nums, dp));
        // last two nums i=0, j=n-3, sum
        ans=max(ans,1+solve(0,n-3,nums[n-1]+nums[n-2],nums, dp));
        // first and last num i=1, j=n-2
        ans=max(ans,1+solve(1,n-2,nums[0]+nums[n-1],nums, dp));
        return ans;
    }
};


int main(){

    return 0;
}