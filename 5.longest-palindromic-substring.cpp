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
class Solution {
public:
    string longest_common_substring(string str1, string str2) 
    {   
        int s1 = str1.size(); int s2 = str2.size();
        int dp[s1+1][s2+1];
        string res ; int max = 0 ;

        for(int i=0; i<=s1; i++)
        {
            for(int j=0; j<=s2; j++)
            {   if(i==0 || j==0){ dp[i][j] = 0;}
             
                else if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    if(dp[i][j]>max)
                    {
                        string temp = str1.substr(i-dp[i][j], dp[i][j]) ;
                        
                        string revtemp = string(temp.rbegin(),temp.rend());
                        if(revtemp==temp)
                        {
                            max = dp[i][j] ;
                            res = temp ;
                        }
                    }
                }
                else
                { dp[i][j] = 0 ; }
            }
        }

        return res;
    }
    string longestPalindrome(string s)
    {
        string srev = string(s.rbegin(),s.rend());
        return longest_common_substring(s, srev); 
    }
};

//  lcs code doesnot work 
class Solution {
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
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= 1+ dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int len= dp[n][m];
        string ans="";
        // for(int i=0;i<len;i++){
        //     ans+='$'; 
        // }
        int idx= len-1;
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+= s1[i-1];
                idx--;
                i--;
                j--;
            }
            else if(dp[i-1][j]> dp[i][j-1])
                i--;
            else
                j--;
        }
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        if(n==0) return "";
        vector<vector<bool>> dp(n, vector<int>(n,0));
        //  every letter is palindrome 
        for(int i=0;i<n;i++){
            dp[i][i]= true;
        }

        string ans="";
        ans+= s[0];

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    
                    if(j-1==1 || dp[i+1][j-1]){

                    }
                }

            }
        }
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