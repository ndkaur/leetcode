/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
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
    bool check(int i, int j, string& s, string& p){
        int n = s.size();
        int m = p.size();
        // when both reached the end reeturn true 
        if(j==m)
            return i==n;
        // * can match null or previcous char's repeated any no of times  
        // . match only curr 1 char
        
        // standing at curr char check if next char is star 
        if(p[j+1]=='*'){ //it is a 
            // we chose star to match null char ' ' 
            if(check(i,j+2, s, p)) // skip the star and move j+=2 to next char 
                return 1;
            // case when chars directly match or its a dot that can match one char 
            while(i<n && (p[j]==s[i] || p[j]=='.')){
                i++;
                // case when we choos * to match null 
                if(check(i, j+2, s, p))
                    return 1;
            }
        }
        // case when directly match or a dot then move both i and j 
        else if(i<n && (p[j]=='.' || s[i]==p[j]) && check(i+1, j+1, s, p))
            return 1;
        return 0;
    }
    bool isMatch(string s, string p) {
        return check(0,0, s, p);
    }
};

// recursion :- O(2^n)
class Solution1 {
public:
    bool check(int i, int j, string& s, string& p){
        int n = s.size();
        int m = p.size();
        // when both reached the end reeturn true 
        if(j==m)
            return i==n;
        // * can match null or previcous char's repeated any no of times  
        // . match only curr 1 char
        
        // standing at curr char check if next char is star 
        if(p[j+1]=='*'){ //it is a star ,
        //  two options:- 1. match null -> (i, j+2)
        // 2.curr char matches '.' -> i+1 , j 
        // curr char got matched and we still keeping star if in futre we require the smae char repetance  
            if(check(i, j+2, s, p) || (i<n && (p[j]=='.' || s[i]==p[j]) && check(i+1, j, s, p)))
                return 1;
        }
        // not a star, but is a '.' and curr char matches , so just move ahead , might be possible its end 
        else if(i<n && (p[j]=='.' || s[i]==p[j]) && check(i+1, j+1, s,p)){
            return 1;
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        return check(0,0, s, p);
    }
};

//  meomization O(n*m)

class Solution2 {
public:
    bool check(int i, int j, string& s, string& p, vector<vector<char>>& dp){
        int n = s.size();
        int m = p.size();
        // when both reached the end reeturn true 
        if(j==m)
            return i==n;
        // * can match null or previcous char's repeated any no of times  
        // . match only curr 1 char
        if(dp[i][j]!=-1)
            return dp[i][j];
        // standing at curr char check if next char is star 
        if(p[j+1]=='*'){ //it is a star ,
        //  two options:- 1. match null -> (i, j+2)
        // 2.curr char matches '.' -> i+1 , j 
        // curr char got matched and we still keeping star if in futre we require the smae char repetance  
            if(check(i, j+2, s, p, dp) || (i<n && (p[j]=='.' || s[i]==p[j]) && check(i+1, j, s, p, dp)))
                return dp[i][j]=1;
        }
        // not a star, but is a '.' and curr char matches , so just move ahead , might be possible its end 
        else if(i<n && (p[j]=='.' || s[i]==p[j]) && check(i+1, j+1, s,p, dp)){
            return dp[i][j]=1;
        }
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<char>> dp(n+1, vector<char>(m+1,-1));
        return check(0,0, s, p, dp);
    }
};


//  bottom up 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,0));
        dp[n][m]=1;
        
        for(int i=n; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(p[j+1]=='*'){ // its a star
                    dp[i][j] = dp[i][j+2] || i<n && (p[j]=='.' || s[i]==p[j]) && dp[i+1][j];
                }
                else // its a dot 
                    dp[i][j] =  i<n && (p[j]=='.' || s[i]==p[j]) && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};


// @lc code=end


int main(){

    return 0;
}