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
class Solution0  { //O(n^3) 
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0; 
        //O(n^2)
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                count += help(s,i,j);
            }
        }
        return count;
    }
    //O(N)
    int help(string &s ,int i , int j){
        if(i>=j) return 1;
        return s[i]==s[j] ? help(s,i+1,j-1):0;
    }
};

class Solution1 { //O(n^2)
public:
    int check(string& s, int i, int j, vector<vector<int>>& dp){
        if(i>=j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 0;
        if(s[i]==s[j])
            ans = check(s, i+1, j-1, dp);
        else 
            ans = 0;
        return dp[i][j] = ans;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                cnt += check(s,i,j,dp);
            }
        }
        return cnt;
    }
};

class Solution1 {
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

// g is gap , to traverse through diagonals 
// when i=5 j=1 its not valid case so we move in half of the matrix 
class Solution { //O(n^2)
public:
    int countSubstrings(string s) {
        int n= s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int count=0;
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){ // when a=a, b=b
                    dp[i][j]=true;
                }else if(gap==1){ // when aa=aa , bb=bb   
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else 
                        dp[i][j]= false;
                }else { // outer side char equal and inner char also equal
                    if(s[i]==s[j] && dp[i+1][j-1]==true) 
                        dp[i][j]= true;
                    else 
                        dp[i][j]=false;
                }
                if(dp[i][j])
                    count++;
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