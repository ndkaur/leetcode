/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
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

// n=1 -> 1
// n=2 -> 2
// n=3 -> 5 -> 2*2 + 1 = 4 + 1 =5
// (i-1)*2 + (i-3)
class Solution {
public:
    int mod = 1e9+7;
    long f(int i, vector<long>& dp){
        if(i<=2)
            return i;
        if(i==3)
            return 5;
        if(dp[i]!=-1)
            return dp[i];
        
        long ans1 = 0;
        long ans2 = 0;

        ans1 = f(i-1, dp)%mod;
        ans2 = f(i-3, dp)%mod;

        dp[i] =  (ans1*2+ans2)%mod;
        return dp[i]%mod;
    }
    int numTilings(int n) {
        vector<long> dp(n+1,-1);
        long ans = f(n, dp)%mod;
        return (int)ans;
    }
};


// @lc code=end


int main(){

    return 0;
}