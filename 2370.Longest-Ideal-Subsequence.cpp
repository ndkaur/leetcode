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

class Solution0 {
public:
    int f(int idx, int prev,  string& s, int& k, vector<vector<int>>& dp){
        int n = s.size();
        if(idx>=n)
            return 0;

        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        
        int pick = 0;
        if(prev==0 || abs(s[idx]-prev)<=k)
            pick = 1+f(idx+1, s[idx], s, k, dp);

        int npick = f(idx+1, prev, s, k, dp);

        return dp[idx][prev] = max(pick, npick);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        // z ascii code = 122
        // z+a = 122 + 25 =147 , so round till 150
        vector<vector<int>> dp(n+1, vector<int>(150, -1));
        return f(0,0,s, k, dp);
    }
};


class Solution0 { //tle
public:
    int longestIdealString(string s, int k) {
        int n= s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(s,n,0,-1,k,dp);
    }
    int f(string& s, int n, int idx, int prev,int k, vector<vector<int>>&dp){
        if(idx==n)
            return 0;
        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];
        int noTake= 0+ f(s,n, idx+1, prev,k, dp);
        int take=0;
        if(prev==-1 || abs(s[idx]-s[prev])<=k)
            take= 1+ f(s,n, idx+1, idx ,k, dp);
        return dp[idx][prev+1] = max(take,noTake);
    }
};


class Solution {
public:
    int longestIdealString(string s, int k) {
        int n= s.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<= i-1; prev++){
                if(abs(s[i]-s[prev])<=k){
                    dp[i] = max(dp[i], 1+ dp[prev]);
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    
};

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n= s.size();
        vector<int> dp(26,0);
        for(int i=0;i<n;i++){
            int c= s[i]-'a';
            int ans=1;
            for(int prev=0;prev<26; prev++){
                if(abs(prev-c)<=k){
                    ans= max(ans, 1+ dp[prev]);
                }
            }
            dp[c]=ans;
        }
        return *max_element(dp.begin(),dp.end());
    }
    
};

int main(){
    Solution sol;
    string s = "acfgbd";
    int k=2;
    int ans = sol.longestIdealString(s,k);
    cout<<ans;
    return 0;
}




