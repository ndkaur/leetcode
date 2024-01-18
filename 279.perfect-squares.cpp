/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
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


class Solution0 {
public:
    int f(int idx, int n, vector<int>& dp){
        if(n==0)
            return 0;
        if(n<0)
            return 1e8;
        if(idx*idx>n)
            return 1e8;

        if(dp[n]!=-1)
            return dp[n];
            
        if(idx*idx<=n){
            // pick , not pick
            return dp[n] = min(1+f(idx, n-(idx*idx), dp), f(idx+1, n, dp));
        }
        return dp[n]=0;

    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(1, n, dp);
    }
};


class Solution {
public:
    int numSquares(int n) {
        if(n<=3)
            return n;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=n; i++){ // loop for num n given 
            for(int j=1; j*j<=i; j++){ // our iterating to reach target 
                dp[i] = min(dp[i], 1+dp[i-j*j]); // npick , pick 
            }
        }
        return dp[n];
    }
};




class Solution0 {
public:
    int numSquares(int n) {
        if(n<=3) return n; 
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1; j*j<=i; j++){
                dp[i]= min(dp[i],1+(dp[i-j*j]));
            }
        }
        return dp.back();
    }
};

// we get each ans in form of perfect sqaure , so we travel in bound of perfect sq.
// j= 1 , 4, 9 until it doesnot exceed the n .
// dp = min of prev dp , dp at that perfct square value 
// to reach at that value we subtarcted j8j from whole lenght which is i .

// @lc code=end
// legendre's theorem  ans is 4 if num in the form of 4^a(8b+7); n = a*a + b*b + c*c
// so possible ans are 1,2,3,4

class Solution {
public:
    int numSquares(int n){
        // if a perfect square 
        if(ceil(sqrt(n)) == floor(sqrt(n)))
            return 1;
        while(n%4==0)
            n/=4;
        if(n%8==7)
            return 4;
        for(int i=1;i*i<=n;i++){
            int base = sqrt(n-i*i);
            if(base*base == (n-i*i))
                return 2;
        }
        return 3;
    }
};

int main(){
    Solution sol;
    int n = 12;
    int ans = sol.numSquares(n);
    cout<<ans;
    return 0;
}