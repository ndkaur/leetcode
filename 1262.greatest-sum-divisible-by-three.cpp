/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
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
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(3));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                if(i==0){
                    int idx = nums[i]%3;
                    dp[i][idx]=max(dp[i][idx],nums[i]);
                }
                else {
                    int idx = (dp[i-1][j]+nums[i])%3;
                    dp[i][idx] = max(dp[i][idx],dp[i-1][j]+nums[i]);
                    dp[i][j]= max(dp[i-1][j],dp[i][j]);
                }
            }
        }
        return dp[n-1][0];
    }
};

// only 3 possiblities  either remainder is 0(exactly divisible), 1, 2
// add nums[i] %3 get remainder , with that reaminder we go to that 
// particular index . 
// fill value at that index by getting max(current val , new value )
// new value = [i-1][j] + nums[i];
// then updating the catual value at the original i ,j 
// by max(curr val , new val )

// @lc code=end


int main(){
    Solution sol;
    vector<int> nums={1,2,3,4,4};
    int ans = sol.maxSumDivThree(nums);
    cout<<ans;
    return 0;
}