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


// Time complexity: O(N.N.K)
// Space complexity: O(N.N.K)
class Solution {
public:
        int f(int i, int j, int k, string& s,vector<vector<vector<int>>>& dp){
            if(i>=j)
                return (i==j)?1:0;
            if(dp[i][j][k]!=-1)
                return dp[i][j][k];
            
            int ans = 0;
            int diff = min(abs(s[i]-s[j]), 26-abs(s[i]-s[j]));
            if(diff<=k)
                ans = max(ans, 2 + f(i+1, j-1, k-diff, s, dp));
            
            return dp[i][j][k] = max({ans, f(i+1, j,k,s, dp), f(i, j-1, k, s, dp)});
            
        }
        int longestPalindromicSubsequence(string s, int k) {
            int n = s.size();
            vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
            int ans= f(0, n-1, k, s, dp);

            // for(int ii=0; ii<n+1; ii++){
            //     for(int jj=0; jj<n+1; jj++){
            //         for(int kk=0; kk<k+1; kk++){
            //             cout<<dp[ii][jj][kk];
            //         }
            //         cout<<endl;
            //     }
            //     cout<<endl;
            // } 
            return ans;
        }
};

int main(){
    Solution sol;
    string s = "abced";
    int k =2;
    int ans = sol.longestPalindromicSubsequence(s,k);
    cout<<ans;
    return 0;
}