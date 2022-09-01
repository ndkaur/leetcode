/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
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
class Solution { //n^2
public:
    string longestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        string ans= lcs(s,s2);
        return ans;
    }
    string lcs(string& s1, string& s2){
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m;j++){
            dp[0][j]=0;
        }
        string ans; 
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                    if(dp[i][j] > mx){
                        string temp = s1. substr(i- dp[i][j], dp[i][j]);
                        string revtemp =temp;
                        reverse(temp.begin(), temp.end());
                        if(temp == revtemp){
                            mx= dp[i][j];
                            ans= temp;
                        }
                    }
                }  
                else
                    dp[i][j]= 0;
            }
        }
        return ans;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        int start=0;
        int end=0;
        int mx=0;

        for(int i=0;i<n;i++){
            //  when string len is odd  both ptrs at same location 
            int a= palAroundCenter(i,i,s);
            // when string len is even both ptrs will be at separet location
            int b= palAroundCenter(i, i+1, s);
            int len= max(a,b);

            //  find the substring of palindrome max len in the original string
            if(len > end-start){
                start= i-(len-1)/2;
                end=  i+ len/2;
            }
        }
        return s.substr(start, end-start+1);
    }
    int palAroundCenter(int l, int r, string& s){
        while(l>=0 && r<=s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
};

// check outer then on basis on inner already checked 
class Solution { //O(n^2)
public:
    string longestPalindrome(string s) {
        int n= s.size();
        string ans;
        int mxlen=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        // our choosing of diagonal depends on the diffrence btw i and j 
        for(int diff=0 ; diff<n; diff++){
            for(int i=0, j= i+diff; j<n; i++, j++){
                // diag with diff = 0
                if(i==j){ // diff==0
                    dp[i][j] =1;
                }
                else if( diff==1){
                    // check if last elem are equal 
                    dp[i][j] = (s[i]==s[j]) ? 2 : 0;
                }
                else{ // for all other diff >1
                    if(s[i] == s[j] &&  dp[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1] + 2; // add 2 cause the outer char are 2 make len of 2
                    }
                }
                // we need to calculate the max len so to return the ans string 
                // len of string at any position is = j-i+1
                if(dp[i][j]){
                    if(j-i+1 > mxlen){
                        mxlen = j-i+1;
                        ans = s.substr(i, mxlen);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    string s="babad";
    string ans= sol.longestPalindrome(s);
    for(auto c:s){
        cout<<c;
    }
    return 0;
}