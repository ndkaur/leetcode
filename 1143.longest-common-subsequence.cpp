/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

// recursively 
class Solution0 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans=0;
        int s1=text1.size();
        int s2= text2.size();
        ans= lcs(0,0,text1,text2);
        return ans;
    }
    int lcs(int i,int j,string & text1, string & text2){
        if(i>=text1.size() || j>=text2.size())
            return 0;
        if(text1[i]==text2[j])
            return 1+lcs(i+1,j+1,text1,text2);
        else{
            int left= lcs(i+1,j,text1,text2);
            int right= lcs(i,j+1,text1,text2);
            return max(left,right);
        }
    } // time limit will exceed
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ans=0;
        int s1=text1.size();
        int s2= text2.size();
        vector<vector<int>> dp(s1,vector<int>(s2,-1));
        ans= lcs(0,0,text1,text2,dp);
        return ans;
    }
    int lcs(int i,int j,string & text1, string & text2, vector<vector<int>> &dp){
        if(i>=text1.size() || j>=text2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            return dp[i][j] = 1+lcs(i+1,j+1,text1,text2,dp);
        else{
            int left= lcs(i+1,j,text1,text2,dp);
            int right= lcs(i,j+1,text1,text2,dp);
            return dp[i][j] = max(left,right);
        }
    } 
};

class Solution1 {
public:
    int longestCommonSubsequence(string text1, string text2) { 
        int s1=text1.size();
        int s2=text2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1,0));
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[s1][s2];
    }
};

// @lc code=end


int main(){
    Solution sol;
    string text1="abc";
    string text2 ="abc";
    int out= sol.longestCommonSubsequence(text1,text2);
    cout<<out;
    return 0;
}