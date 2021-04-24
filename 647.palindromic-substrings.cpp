/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
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
class Solution0  {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                count += help(s,i,j);
            }
        }
        return count;
    }
    int help(string &s ,int i , int j){
        if(i>=j) return 1;
        return s[i]==s[j] ? help(s,i+1,j-1):0;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i =n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j)
                    dp[i][j]=1;
                else if (i+1==j)
                    dp[i][j] = s[i]==s[j] ? 1:0;
                else 
                    dp[i][j] = s[i]==s[j] ? dp[i+1][j-1]:0;
                count+=dp[i][j];
            }
        }
        return count;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s = "abc";
    int ans = sol.countSubstrings(s);
    cout<<ans;
    return 0;
}