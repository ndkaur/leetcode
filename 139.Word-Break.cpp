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

// recursion //O(2^n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        return f(0,s, st);
    }
    int f(int i, string& s, set<string>& st){
        int n= s.size();
        if(i==n)
            return 1;
        string temp;
        for(int j=i; j<n; j++){
            temp += s[j];
            if(st.find(temp)!= st.end()){
                if(f(j+1, s, st))
                    return 1;
            }
        }
        return 0;
    }
}; 

// memoization  time->O(n)  space->O(n)+O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s, st,dp);
    }
    int f(int i, string& s, set<string>& st, vector<int>& dp){
        int n= s.size();
        if(i==n)
            return 1;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i; j<n; j++){
            temp += s[j];
            if(st.find(temp)!= st.end()){
                if(f(j+1, s, st,dp))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
}; 

// tabulation 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(n==0) return false;

        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        
        vector<int > dp(n+1,0);
        dp[n] = 1;

        for(int i= n-1; i>=0; i--){
            string temp ="";
            for(int j=i; j<n; j++){
                temp += s[j];
                if(st.find(temp) != st.end()){
                    if(dp[j+1])
                        dp[i]=1;
                }
            }
        }
        return dp[0];
    }
}; 
 


int main(){
    Solution sol;
    string s="leetcode";
    vector<string> worddict= {"leet","code"};
    bool ans = sol.wordBreak(s,worddict);
    cout<<ans;
    return 0;
}