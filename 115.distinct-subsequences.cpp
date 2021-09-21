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
class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int> (m+1));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) // previous ch are equal
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-1]; // side diagonal +side val
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
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