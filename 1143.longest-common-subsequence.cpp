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
}; // tc- o(n*m)  // sc-> o(n*m)+ o(n+m)

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


/////// striver dp series 

class Solution0 {
public:
    int f(string t1, string t2, int i1, int i2){
        if(i1<0 || i2<0) return 0;
        if(t1[i1]==t2[i2]){
            return 1+ f(t1, t2, i1-1, i2-1);
        }
        else{
            return max(f(t1, t2,i1-1,i2), f(t1, t2,i1, i2-1));
        }
    }
    int longestCommonSubsequence(string t1, string t2) {
        int s1= t1.size();
        int s2= t2.size();
        return f(t1, t2, s1-1, s2-1);
    }
};

class Solution1 {
public:
    int f(string t1, string t2, int i1, int i2, vector<vector<int>>& dp){
        if(i1<0 || i2<0) return 0;
        
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        
        if(t1[i1]==t2[i2]){
            return dp[i1][i2]=1+ f(t1, t2, i1-1, i2-1,dp);
        }
        else{
            return dp[i1][i2]=max(f(t1, t2,i1-1,i2,dp), f(t1, t2,i1, i2-1,dp));
        }
    }
    int longestCommonSubsequence(string t1, string t2) {
        int s1= t1.size();
        int s2= t2.size();
        vector<vector<int>> dp(s1, vector<int>(s2,-1));
        return f(t1, t2, s1-1, s2-1,dp);
    }
};

class Solution2 { // change of base case by shift of index one ahead
public:
    int f(string t1, string t2, int i1, int i2, vector<vector<int>>& dp){
        if(i1==0 || i2==0) return 0;
        
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        
        if(t1[i1-1]==t2[i2-1]){
            return dp[i1][i2]=1+ f(t1, t2, i1-1, i2-1,dp);
        }
        else{
            return dp[i1][i2]=max(f(t1, t2,i1-1,i2,dp), f(t1, t2,i1, i2-1,dp));
        }
    }
    int longestCommonSubsequence(string t1, string t2) {
        int s1= t1.size();
        int s2= t2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1,-1));
        return f(t1, t2, s1, s2,dp);
    }
};

class Solution { 
public:
    int longestCommonSubsequence(string t1, string t2) {
        int s1= t1.size();
        int s2= t2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1,0));
        // base case
        for(int i=0;i<=s1;i++)   // <= cause index have been shifted 
            dp[i][0]=0;
        for(int j=0;j<=s2;j++)
            dp[0][j]=0;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(t1[i-1]==t2[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s1][s2];
    }
};


class Solution { 
public:
    int longestCommonSubsequence(string t1, string t2) {
        int s1= t1.size();
        int s2= t2.size();
        vector<int> prev(s2+1,0);
        vector<int> curr(s2+1,0);
        // base case
        
        for(int j=0;j<=s2;j++)
            prev[j]=0;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(t1[i-1]==t2[j-1])
                    curr[j]= 1+prev[j-1];
                else 
                    curr[j]= max(prev[j], curr[j-1]);
            }
            prev= curr;
        }
        return prev[s2];
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



//  to print the longest commom subsequence 

class Solution { 
public:
    int longestCommonSubsequence(string t1, string t2) {
        int s1= t1.size();
        int s2= t2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1,0));
        // base case
        for(int i=0;i<=s1;i++) 
            dp[i][0]=0;
        for(int j=0;j<=s2;j++)
            dp[0][j]=0;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(t1[i-1]==t2[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // to print 
        int len= dp[s1][s2];
        string ans="";
        for(int i=0;i<len;i++)
            ans+='$';

        int idx= len-1; // last index
        int i=s1;
        int j= s2;
        while(i>0 && j>0){
            if(t1[i]==t2[j]){
                ans[idx]= t1[i-1];
                idx--;
                i--;
                j--;
            } // we just print onlt the common subsequences 
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        cout<<ans;
    }
};