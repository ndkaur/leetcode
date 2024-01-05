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

class Solution1 {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp (n,vector<int>(n));
        return help(0,n-1,s,dp);
    }
    int help(int left, int right, string s, vector<vector<int>>& dp){
        if(left==right) return 1;
        if(left>right) return 0;
        if(dp[left][right]) return dp[left][right];
        return dp[left][right] = (s[left]==s[right]) ? 2+help(left+1,right-1,s,dp) : max(help(left+1,right, s, dp), help(left,right-1,s,dp));
    } // time elimit exceed
};


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


class Solution3 {
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

class Solution { // using logic of lcs
public:
    int longestPalindromeSubseq(string a) {        
        string b=a;
        reverse(b.begin(),b.end());
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){ // stating both row and coloumn filled with 0 
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// RECURSIVE USING LONGEST COMMON SUBSEQUENCE LOGIC 
class Solution {
public:
    int f(int i, int j,string& s1, string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        else 
            return dp[i][j]= max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s1) {
        int n= s1.size();
        string s2= s1;
        reverse(s2.begin(), s2.end());
        int m= s2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(n-1, m-1,s1, s2,dp);
    }
};



// 0 diff diagonal -> {1,1}, {2,2}, {3,3} j=i+diff
//1 diff diagonal-> {0,1} ,{1,2}, {2,3} , j= 0+1 = i+diff
// 2diff diagonal -> {0,2}, {1,3}
class Solution { // using diagonal approach 
public:
    int longestPalindromeSubseq(string s) {        
        int n = s.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int diff=0; diff<n; diff++){
            for(int i=0,j=i+diff; j<n; i++, j++){
                if(i==j){ //diagonal =0
                    dp[i][j] = 1;
                }
                else if(diff==1){
                    dp[i][j] = (s[i]==s[j]) ? 2:1;
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    else  // remining inbetween string not equal 
                        dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

// @lc code=end


int main(){
    Solution sol;
    string s = "cbbde";
    int ans = sol.longestPalindromeSubseq(s);
    cout<<ans;
    return 0;
}