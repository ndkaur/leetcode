/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
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
    int minCostClimbingStairs(vector<int>& cost) {
        int len =cost.size();
        int f1=0,f2=0;
        for(int i=len-1;i>=0;i--){
            int f0= cost[i]+min(f1,f2);
            f2=f1;
            f1=f0;
        }
         return min(f1,f2);
    }
};

// by dynamic programming

class Solution {
    const int inf = 1e7;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int  n = cost.size();
        // n+1+2 depends on next two values also
        vector<int> dp(n+3);
        dp[n] = dp[n+1] = 0;
        for(int i=n-1; i>=0; --i){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        
        return min(dp[0], dp[1]);
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> cost={1,100,1,1,1,100,1,1,100,1};
    int ans=sol.minCostClimbingStairs(cost);
    cout<<ans;
    return 0;
}