/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else 
                j++;
        }
        if(i==s.length())
            return true;
        else 
            return false;
    }
};

class Solution {
public:
    int help(string s, string t){
        int n=s.size();
        int m= t.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]= 1+ dp[i-1][j-1];
                else 
                    dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    bool isSubsequence(string s, string t) {
        int x= help(s,t);
        if(x == s.size())
            return true;
        else 
            return false;
    }
};

class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        int j=0;
        for(int i=0;i<n;i++){
            if(s[j]==t[i]){
                j++;
            }
        }
        return j==m;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="abc";
    string t="ahbcd";
    bool out=sol.isSubsequence(s,t);
    cout<<out;
    return 0;
}