/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
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
class Solution0 {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        return help(0,n-1,s);
    }
    int help(int left, int right , string s){
        if(left==right) return 1;
        if(left>right)  return 0;
        int ans = (s[left]==s[right]) ? 2+help(left+1,right-1,s) : max(help(left+1,right,s), help(left,right-1,s));
        return ans;
    }
}; /// time limit exceeded 

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n=s.size();
//         vector<vector<int>>dp (n,vector<int>(n));
//         return help(0,n-1,s,dp);
//     }
//     int help(int left, int right, string s, vector<vector<int>>& dp){
//         if(left==right) return 1;
//         if(left>right) return 0;
//         if(dp[left][right]) return dp[left][right];
//         return dp[left][right] = (s[left]==s[right]) ? 2+help(left+1,right-1,s,dp) : max(help(left+1,right, s, dp), help(left,right-1,s,dp));
//     } // time elimit exceed
// };


class Solution2 {
    int dp[1001][1001]={};
public:
    int solve(string &s,int l,int r){
        if(l>r)
            return 0;
        if(l==r)
            return 1;
        return dp[l][r] ? dp[l][r] : dp[l][r]=
            (s[l]==s[r] ? solve(s,l+1,r-1)+2 : max(solve(s,l+1,r),solve(s,l,r-1)));
    }
    int longestPalindromeSubseq(string s) {        
        return solve(s,0,s.length()-1);
    }
};


class Solution {
public:
    int longestPalindromeSubseq(string s) {        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int l=n-1;l>=0;l--){
            dp[l][l] =1;
            for(int r=l+1;r<n;r++){
                if(s[l]==s[r])
                    dp[l][r] = 2+dp[l+1][r-1];
                else 
                    dp[l][r] = max(dp[l+1][r],dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s = "abbd";
    int ans = sol.longestPalindromeSubseq(s);
    cout<<ans;
    return 0;
}