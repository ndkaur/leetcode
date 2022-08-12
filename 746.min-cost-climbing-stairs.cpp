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

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(i<2) 
                dp[i]=cost[i];
            else 
                dp[i]= cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
// @lc code=end

// rcursion 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        return f(n,cost);
    }
    int f(int i, vector<int>& cost){
        int n= cost.size();
        if(i==0 || i==1)
            return 0;
        
        int one = cost[i-1] + f(i-1,cost);
        int two= cost[i-2] + f(i-2,cost);
        return min(one,two);
    }
};

// memoization 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,-1);
        return f(n,cost,dp);
    }
    int f(int i, vector<int>& cost,vector<int>& dp){
        int n= cost.size();
        if(i==0 || i==1)
            return 0;
        if(dp[i]!=-1) 
            return dp[i];
        
        int one = cost[i-1] + f(i-1,cost,dp);
        int two= cost[i-2] + f(i-2,cost,dp);
        return dp[i]= min(one,two);
    }
};

//tabulation 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<dp.size();i++){
            dp[i] = min( cost[i-1]+ dp[i-1] , cost[i-2]+ dp[i-2]);
        }
        return dp[dp.size()-1];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        return min(f(0,cost),f(1,cost));
    }
    int f(int i, vector<int>& cost){
        int n= cost.size();
        if(i>=n)
            return 0;
        int one= cost[i] + f(i+1,cost);
        int two = cost[i] + f(i+2,cost);
        return min(one,two);
    }
};

int main(){
    Solution sol;
    vector<int> cost={1,100,1,1,1,100,1,1,100,1};
    int ans=sol.minCostClimbingStairs(cost);
    cout<<ans;
    return 0;
}