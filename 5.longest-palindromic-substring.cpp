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