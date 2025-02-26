/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
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
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n= s.size();
//         int m= t.size();
//         vector<vector<unsigned int>> dp(n+1,vector<unsigned int> (m+1));
//         for(int i=0;i<n;i++)
//             dp[i][0]=1;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1]==t[j-1]) // previous ch are equal
//                     dp[i][j] = dp[i-1][j]+dp[i-1][j-1]; // side diagonal +side val
//                 else 
//                     dp[i][j] = dp[i-1][j];
//             }
//         }
//         return dp[n][m];
//     }
// };

// RECURSION  tc-> o 2^n * 2^m
class Solution0 {
public:
    int f(int i,int j,string& s, string& t){
        if(j<0) return 1; // j went -1 means each char matched with i
        if(i<0) return 0; // i went -1 
        if(s[i]==t[j])
            return (f(i-1,j-1,s,t) + f(i-1,j,s,t) ); // change both index or change only i index
        return f(i-1,j,s,t); 
    }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        return f(n-1,m-1,s,t);
    }
};

//  when equal -> dp[i-1][j-1] (we take val and move both our index ahead) + dp[i-1][j]( we move only i ahead and want to find other occurences of j)
//  memoization -> tc o(m*n)  sc->o(m*n)+ o(m+n)
class Solution1 {
public:
    int f(int i,int j,string& s, string& t,vector<vector<int>>&dp){
        if(j<0) return 1; // j went -1 means each char matched with i
        if(i<0) return 0; // i went -1 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=(f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp) ); // change both index or change only i index
        return dp[i][j]= f(i-1,j,s,t,dp); 
    }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};


class Solution2 {
public:
    int f(int i,int j,string& s, string& t,vector<vector<int>>&dp){
        if(j<0) return 1; // j went -1 means each char matched with i
        if(i<0) return 0; // i went -1 
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=(f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp) ); // change both index or change only i index
        return dp[i][j]= f(i-1,j,s,t,dp); 
    }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};

class Solution3 { // another way to write to deal with -1 case move one index ahead
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]= dp[i-1][j-1]+ dp[i-1][j];
                else 
                    dp[i][j]= dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};

//  space optimization 
class Solution6 { 
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<double> curr(m+1,0);
        vector<double> prev(m+1,0);
        prev[0]=curr[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    curr[j]= prev[j-1]+ prev[j];
                else 
                    curr[j]= prev[j];
            }
            prev= curr;
        }
        return (int)prev[m];
    }
};

class Solution5 { 
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<double> prev(m+1,0);
        prev[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1])
                    prev[j]= prev[j-1]+ prev[j];
            }
        }
        return (int)prev[m];
    }
};


class Solution {
    public:
        int f(int i, int j, string& s, string& t, vector<vector<int>>& dp){
            if(j==0)
                return 1;
            if(i==0)
                return 0;
            if(dp[i][j]!=-1)
                return dp[i][j];
    
            if(s[i-1]==t[j-1]){
                return dp[i][j] = f(i-1,j-1, s, t, dp) + f(i-1, j, s, t, dp);
            }
            return dp[i][j] = f(i-1, j, s, t, dp);
        }
        int numDistinct(string s, string t) {
            int n = s.size();
            int m = t.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
            
            // for(int i=0; i<dp.size(); i++){
            //     for(int j=0; j<dp[0].size(); j++){
            //         cout<<dp[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            return f(n, m, s, t, dp);
        }
    };


// @lc code=end


int main(){
    Solution sol;
    string s="babgbag";
    string t ="bag";
    int ans = sol.numDistinct(s,t);
    cout<<ans;
   return 0;
}

// "babgbag"
// "bag"


//      0 b a g
// 0    1 0 0 0 
// b    1 1 0 0 
// a    1 1 1 0 
// b    1 2 1 0 
// g    1 2 1 1 
// b    1 3 1 1 
// a    1 3 4 1 
// g    1 3 4 5  

// i= b a b g
// j= b   
// no of ways = 2

// i= b a b g a
// j= b a
// no of ways = 4

// if equal -> [i-1][j-1]  + [i-1][j]
// not equal  -> [i-1][j]

// every box tells no of way to make till i in j 