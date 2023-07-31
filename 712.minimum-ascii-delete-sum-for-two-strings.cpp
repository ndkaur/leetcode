/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

// finding the lcs array and then totalsum - 2*lcsum 
// this spproach doesnot work 
// as we want min ascii sum but there may be possible that two lcs exist 
// delete , leet -> 
//lcs = let ,  lee , eet so our lcs will find lcs as let and it can give max val also 
//so its better to make a dp with the sum itself;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int sum =0;
        for(int i=0; i<n; i++){
            sum += (int)s1[i];
        }
        for(int j=0; j<m; j++){
            sum += (int)s2[j];
        }
        cout<<sum<<endl;
        // lcs 
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int lcs =  dp[n][m];
        string ans;

        int i = n;
        int j = m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            } 
            else 
                j--;
        }
        reverse(ans.begin(), ans.end());
        for(auto ch:ans){
            cout<<ch;
        }
        int lcsSum = 0;
        for(int i=0; i<ans.size(); i++){
            lcsSum += (int)ans[i];
        }
        cout<<lcsSum<<endl;
        return sum- 2*lcsSum;
    }
};

// corrct answer 

// s1 = "delete", s2 = "leet"
0,108,209,310,426,
100,208,309,410,526,
201,309,208,309,425,
309,201,302,403,519,
410,302,201,302,418,
526,418,317,418,302,
627,519,418,317,403,
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n= s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=1;j<=m;j++)
            dp[0][j] = dp[0][j-1]+s2[j-1];
        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][0]+s1[i-1];
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

int main(){ 
    Solution sol;
    string s1="delete";
    string s2="leet";
    int ans= sol.minimumDeleteSum(s1,s2);
    cout<<ans;
    return 0;
}