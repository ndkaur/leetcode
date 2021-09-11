/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start

class Solution0 {
public:
    string stoneGameIII(vector<int>& s) {
        int aliceWinCheck = help(s,0);
        if(aliceWinCheck>0) return "Alice";
        if (aliceWinCheck==0) return "Tie";
        return "Bob";
    }
    int help(vector<int>& s, int i){
        int n= s.size();
        if(i>=n) return 0;
        else{
            int ans =INT_MIN;
            ans = max(ans,s[i]-help(s,i+1)); // i=1
            if(i+1<n) ans = max(ans,s[i]+s[i+1] - help(s,i+2)); // i=2
            if(i+2<n) ans = max(ans,s[i]+s[i+1]+s[i+2] - help(s,i+3)) ; // i=3
            return ans;
        }
    }
};  // time limit exceeded 

class Solution1 {
public:
    string stoneGameIII(vector<int>& s) {
        int n= s.size();
        vector<int> dp(n+1,-1);
        int aliceWinCheck = help(s,0,dp);
        if(aliceWinCheck>0) return "Alice";
        if (aliceWinCheck==0) return "Tie";
        return "Bob";
    }
    int help(vector<int>& s, int i,vector<int>&dp){
        int n= s.size();
        if(dp[i]!=-1) return dp[i];
        if(i>=n) return 0;
        else{
            int ans =INT_MIN;
            ans = max(ans,s[i]-help(s,i+1,dp)); // i=1
            if(i+1<n) ans = max(ans,s[i]+s[i+1] - help(s,i+2,dp)); // i=2
            if(i+2<n) ans = max(ans,s[i]+s[i+1]+s[i+2] - help(s,i+3,dp)) ; // i=3
            return dp[i]=ans;
        }
    }
};

class Solution2 {
public:
    string stoneGameIII(vector<int>& s) {
        int n= s.size();
        vector<int> dp(n+1,0);
        int i=n-1;
        while(i>=0){
            int ans =INT_MIN;
            ans = max(ans,s[i]-dp[i+1]); // i=1
            if(i+1<n) ans = max(ans,s[i]+s[i+1] - dp[i+2]); // i=2
            if(i+2<n) ans = max(ans,s[i]+s[i+1]+s[i+2] - dp[i+3]) ; // i=3
            dp[i]=ans;
            i--;
        }
        int aliceWinCheck = dp[0];
        if(aliceWinCheck>0) return "Alice";
        if (aliceWinCheck==0) return "Tie";
        return "Bob";
    }
};

class Solution {
public:
    string stoneGameIII(vector<int>& s) {
        int n= s.size();
        int i1=0,i2=0,i3=0; 
        int i=n-1;
        while(i>=0){
            int ans =INT_MIN;
            ans = max(ans,s[i]-i1); // i=1
            if(i+1<n) ans = max(ans,s[i]+s[i+1] - i2); // i=2
            if(i+2<n) ans = max(ans,s[i]+s[i+1]+s[i+2] - i3) ; // i=3
            i3=i2;
            i2=i1;
            i1=ans;
            i--;
        }
        int aliceWinCheck =i1;
        if(aliceWinCheck>0) return "Alice";
        if (aliceWinCheck==0) return "Tie";
        return "Bob";
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> values ={1,2,3,7};
    string ans = sol.stoneGameIII(values);
    for(auto c:ans) cout<<c;
   return 0;
}