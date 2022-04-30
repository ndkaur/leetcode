/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
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

// logic-> find lcs then we take the common string only ones and the rest left string we take 
//  n+m- len of lcs -> print all the chars by visting all
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0)); // 1 base indexing
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]== s2[j-1])
                    dp[i][j]= 1+ dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int l= dp[n][m];
        int len= n+m -l;
        //  print 
        int i=n;
        int j= m;
        string ans="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+= s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+= s1[i-1];
                i--;
            }
            else{
                ans+= s2[j-1];
                j--;
            }
        }
        //  including those are left 
        while(i>0){
            ans+= s1[i-1];
            i--;
        }
        while(j>0){
            ans+= s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s1= "abac";
    string s2= "cab";
    string ans= sol.shortestCommonSupersequence(s1,s2);
    for(auto c: ans){
            cout<<c;
    }
    return 0;
}