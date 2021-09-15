/*
 * @lc app=leetcode id=1563 lang=cpp
 *
 * [1563] Stone Game V
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution0{
public:
    int stoneGameV(vector<int>& s){
        int n = s.size();
        return help(0,n-1,s);
    }
    int help(int start, int end , vector<int>& s){
        if(start>end) return 0;
        int r=0;
        for(int i=start;i<=end;i++)
            r+= s[i];
        int l=0;
        int ans=0;
        for(int i=start;i<end;i++){
            l+=s[i];
            r-=s[i];
            if(l>r)
                ans = max(ans, r+help(i+1,end,s));
            if(r>l)
                ans = max(ans,l+help(start,i,s));
            if(l==r)
                ans = max(ans , l+ max(help(start,i,s),help(i+1,end,s)));
        }
        return ans;
    } 
};  // time limit exceeded 


class Solution {
public:
    int stoneGameV(vector<int>& s){
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(0,n-1,s,dp);
    }
    int help(int start, int end , vector<int>& s,vector<vector<int>>& dp){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int r=0;
        for(int i=start;i<=end;i++)
            r+= s[i];
        int l=0;
        int ans=0;
        for(int i=start;i<end;i++){
            l+=s[i];
            r-=s[i];
            if(l>r)
                ans = max(ans, r+help(i+1,end,s,dp));
            if(r>l)
                ans = max(ans,l+help(start,i,s,dp));
            if(l==r)
                ans = max(ans , l+ max(help(start,i,s,dp),help(i+1,end,s,dp)));
        }
        return dp[start][end]=ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> stone ={6,2,3,4,5,5};
    int ans = sol.stoneGameV(stone);
    cout<<ans;
    return 0;
}