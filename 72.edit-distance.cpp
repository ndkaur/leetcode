/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
class Solution0 {
public:
    int minDistance(string word1, string word2) {
        int ans =editdistance(0,0,word1,word2);
        return ans;
    }
    int editdistance(int i,int j , string & word1,string & word2){
        // base condition
        //deletaing remaining letters after first word is formed
        if(i==word1.size()) return word2.size()-j; 
        if(j==word2.size()) return word1.size()-i;
        if(word1[i]==word2[j])
            return editdistance(i+1,j+1,word1,word2);
        else {
            // abc/dc insert d -> Dabc/dC 
            int insert = 1+ editdistance(i,j+1,word1,word2);
            int del = 1+ editdistance(i+1,j,word1,word2);
            // for replace  delete and then insert
            int replace = 1+ editdistance(i+1,j+1,word1,word2);
            return min(insert,min(del,replace));
        }
        return -1;
    }
};

class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<vector<int>> dp= vector<vector<int>>(n+1,vector<int>(m+1,-1));
        int ans = editdistance(0,0,word1,word2,dp);
        return ans;
    }
    int editdistance(int i,int j, string & word1, string & word2,vector<vector<int>> & dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==word1.size()) return dp[i][j] = word2.size()-j;
        if(j==word2.size()) return dp[i][j] = word1.size()-i;
        if(word1[i]==word2[j])
            return dp[i][j] = editdistance(i+1,j+1,word1,word2,dp);
        else {
            int insert = 1+ editdistance(i,j+1,word1,word2,dp);
            int del = 1+ editdistance(i+1,j,word1,word2,dp);
            int replace = 1+ editdistance(i+1,j+1,word1,word2,dp);
            return dp[i][j] = min(insert,min(del,replace));
        }
        return -1;
    }
};


class Solution2 {
    vector<vector<int>> dp;
public:
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        dp= vector<vector<int>>(n+1,vector<int>(m+1,-1));
        int ans = editdistance(0,0,word1,word2);
        return ans;
    }
    int editdistance(int i,int j, string & word1, string & word2){
       
        int &ans = dp[i][j];
        if(ans!=-1) return ans;
        if(i==word1.size()) return ans = word2.size()-j;
        if(j==word2.size()) return ans = word1.size()-i;
        if(word1[i]==word2[j])
            return ans = editdistance(i+1,j+1,word1,word2);
        else {
            int insert = 1+ editdistance(i,j+1,word1,word2);
            int del = 1+ editdistance(i+1,j,word1,word2);
            int replace = 1+ editdistance(i+1,j+1,word1,word2);
            return ans = min(insert,min(del,replace));
        }
        return -1;
    }
};

class Solution3 {
public:
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<vector<int>> dp (n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=1;j<=m;j++){
            dp[0][j]=j;
        }
        // bottom -up approach 
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int repeat= dp[i-1][j-1] + (word1[i-1]!=word2[j-1]);
                int insert= dp[i][j-1]+1;
                int del = dp[i-1][j]+1;
                // will replace only when words arnt equal
                dp[i][j] =min({insert,del,repeat});
            }  
        }
        return dp[n][m];
    }
};

// single dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<int> dist(m+1);
        for(int j=1;j<=m;j++){
            dist[j]=j;
        }
        for(int i=1;i<=n;i++){
            vector<int> ndist(m+1);
            ndist[0]=i;
            for(int j=1;j<=m;j++){
                int replace= dist[j-1]+ (word1[i-1]!=word2[j-1]);
                int insert= ndist[j-1]+1;
                int del = dist[j]+1;
                ndist[j]=min(replace,min(insert,del));
            }
            dist=ndist;
        }
        return dist[m];
    }
};

// RECURSION

class Solution {
public:
    int f(int i, int j, string w1, string w2){
        if(i<0) // w1 is exhausted insert he remaining of j into i 
            return j+1;
        if(j<0) // w2 is exhausted , delete the remining i 
            return i+1;
        if(w1[i]==w2[j])  // matched
            return 0+f(i-1,j-1,w1,w2);
        // not matched 
        return 1+min(f(i,j-1,w1,w2), min(f(i-1,j,w1,w2),f(i-1,j-1,w1,w2))); 
//         insert delted replace
    }
    int minDistance(string w1, string w2) {
        int n= w1.size();
        int m= w2.size();
        return f(n-1,m-1,w1,w2);
    }
};

//  MEMOIZATION
class Solution {
public:
    int f(int i, int j, string w1, string w2,vector<vector<int>>& dp){
        if(i==0) // w1 is exhausted insert he remaining of j into i 
            return j;
        if(j==0) // w2 is exhausted , delete the remining i 
            return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i-1]==w2[j-1])  // matched
            return dp[i][j]= 0+f(i-1,j-1,w1,w2,dp);
        // not matched 
        return dp[i][j]= 1+min(f(i,j-1,w1,w2,dp), min(f(i-1,j,w1,w2,dp),f(i-1,j-1,w1,w2,dp))); 
//         insert delete replace
    }
    int minDistance(string w1, string w2) {
        int n= w1.size();
        int m= w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1)); // 1 base indexing 
        return f(n,m,w1,w2,dp);
    }
};

//  TABULATION 
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n= w1.size();
        int m= w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0)); // 1 base indexing 
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int j=0;j<=m;j++)
            dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
};

 
// @lc code=end


int main(){
    Solution sol;
    string word1="horse";
    string word2="ros";
    int ans=sol.minDistance(word1,word2);
    cout<<ans;
    return 0;
}


//   0 a b c d e f
//   0 1 2 3 4 5 6
// a 1 0 1 2 3 4 5
// z 2 1 1 2 3 4 5
// c 3 2 2 1 2 3 4
// e 4 3 3 2 2 2 3
// d 5 4 4 3 2 3 3

// ans depends on   if equal return diagonal   , if not then min of i-1,j-1,diagonal
// if(w1[i]==w2[j])
//     dp[i][j]= dp[i-1][j-1]
// else 
//     dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])
