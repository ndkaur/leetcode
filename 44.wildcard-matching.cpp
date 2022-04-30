/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
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
class Solution0 {
public:
    int f(int i, int j, string s, string p){
        // base case
        if(i<0 && j<0) return true; // both exhausted
        if(i<0 && j>=0){// string ended but pattern is remaining 
            for(int idx=0;idx<=j;idx++){ // j left in pattern if *
                if(p[idx]!= '*' ) 
                    return false; 
            } // if * can be empty 
            return true; // if ? cant be empty
        }
        if(j<0 && i>=0){ // pattern ended but string remaining
            return false;
        }

        if(s[i]==p[j] || p[j] =='?')
            return f(i-1,j-1,s,p);
        
        if(p[j]=='*'){ // if any one true the answer is true
            return f(i-1,j,s,p) | f(i,j-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        return f(n-1,m-1,s,p);
    }
};

class Solution1 {
public:
    int f(int i, int j, string s, string p,vector<vector<int>>& dp){
        // base case
        if(i<0 && j<0) return true; // both exhausted
        if(i<0 && j>=0){// string ended but pattern is remaining 
            for(int idx=0;idx<=j;idx++){ // j left in pattern if *
                if(p[idx]!= '*' ) 
                    return false; 
            } // if 8 can be empty 
            return true; // if ? cant be empty
        }
        if(j<0 && i>=0){ // pattern ended but string remaining
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j] =='?')
            return dp[i][j]= f(i-1,j-1,s,p,dp);
        
        if(p[j]=='*'){ // if any one true the answer is true
            return dp[i][j]= f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);
        }
        return dp[i][j]= false;
    }   
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};


class Solution {
public:
    bool isMatch(string s, string p) {
        int n= s.size();
        int m= p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i=1;i<=n;i++){ // j= pattern empty , i->string present 
            dp[i][0]= false;
        }
        for(int j=1;j<=m;j++){ // i string empty ,p-> pattern remaining 
            int flag= true;
            for(int idx=1;idx<=j;idx++){
                if(p[idx-1]!='*'){
                    flag= false;
                    break;
                }
            }
            dp[0][j]= flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='?')
                    dp[i][j]= dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else 
                    dp[i][j]= false;
            }
        }
        return dp[n][m];
    }
};

// @lc code=end


int main(){
    Solution sol;
    string s="aa";
    string p="*";
    bool ans = sol.isMatch(s,p);
    cout<<ans;
    return 0;
}