/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
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
    int climbStairs(int n) {
        if(n==1)
            return 1;
        int first=1;
        int second=2;
        for(int i=3;i<=n;i++){
            int third=first+second;
            first=second;
            second=third;
        }
        return second;
    }
};


// Time: O(2^n) ; Space: O(n)
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
      
        return climbStairs(n-1)+climbStairs(n-2);
    }
};


class Solution { //O(n) O(n)
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
      
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


class Solution { //O(n) O(1)
public:
    int climbStairs(int n) {
        if(n==1) return n;
      
        int prev1 =1;
        int prev2 =2;
        for(int i=2; i<n; i++){
            int curr  = prev1 + prev2;
            prev1= prev2;
            prev2= curr;
        }
        return prev2;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=3;
    int ans=sol.climbStairs(n);
    cout<<ans;
    return 0;
}