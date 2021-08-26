/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
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
class Solution0 { // time limit exceeded 
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return check(n,2,dp);
    }
    int check(int n, int egg, vector<vector<int>> dp){
        if(dp[n][egg]!=-1) return dp[n][egg];
        if(n<=1) return n;
        if(egg==1) return n;
        int mn= 1e6;
        for(int i=1;i<n;i++){ // break            // no break
            mn= min(mn,max(check(i-1,egg-1,dp),check(n-i,egg,dp)+1));
        }
        return dp[n][egg] = mn;
    }
};

class Solution1 {
public:
    int twoEggDrop(int n){
        vector<int> dp(n+1);
        if(n<=1) return n;
        if(dp[n]==0){
            for(int i=1;i<=n;i++){
                dp[n]= min(dp[n]==0 ? n : dp[n], 1+ max(i-1,twoEggDrop(n-i)));
            }
        } 
        return dp[n];
    }
};

class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(3);
        int egg=2;
        int tdrop=0;
        while(dp[egg]<n){
            tdrop++;
            for(int i=egg;i>0;i--)
                dp[i]+= dp[i-1]+1;
        }
        return tdrop;
    }
};



// @lc code=end


int main(){
    Solution sol;
    int n =100;
    int ans = sol.twoEggDrop(n);
    cout<<ans;
    return 0;
}