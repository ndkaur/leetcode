/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

//O(2^n)
class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        int ans = f(0, s);
        return ans;
    }
    int f(int idx, string& s){
        int n= s.size();
        if(idx==n)
            return 1;
        if(s[idx]=='0')
            return 0;
        int one = f(idx+1, s);
        int two= 0;
        // if two digit can be 1__(0-9)  or 2__(0-6)
        // eg digit is 28  26< 28 so not aloowed (i i+1) <= 2 6
        if(idx+1 < n && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<'7')))
            two = f(idx+2,s);
        return one+two;
    }
};

//O(n)
class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int> dp(n,-1);
        int ans = f(0, s,dp);
        return ans;
    }
    int f(int idx, string& s, vector<int>& dp){
        int n= s.size();
        if(idx==n)
            return 1;
        if(s[idx]=='0')
            return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one = f(idx+1, s, dp);
        int two= 0;
        // if two digit can be 1__(0-9)  or 2__(0-6)
        if(idx+1 < n && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<'7')))
            two = f(idx+2,s,dp);
        return dp[idx]=  one+two;
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0')
                dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
                    dp[i] += dp[i+2];
            }
        }
        return s.empty() ? 0: dp[0];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        int nxt= 1;
        int nnxt;
        
        for(int i=n-1; i>=0; i--){
            int cur = s[i] =='0' ? 0 : nxt;
            if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
                    cur += nnxt;
            nnxt= nxt;
            nxt= cur;
        }
        return s.empty() ? 0: nxt;
    }
};
// @lc code=end


int main(){

    return 0;
}