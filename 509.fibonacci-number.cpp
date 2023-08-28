/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

// recursion 

class Solution0 {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);
    }
}; // o(n2)
    
class Solution1 {
public: 
    int fib(int n) {
        if(n<2)
            return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    } // o(n)
};


class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        int a=0,b=1,c=0;
        for(int i=1;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        } 
        return c;
    }
};


class Solution { //O(N)
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        int a =0;
        int b = 1;
        int c =0;
        for(int i=2; i<=n; i++){
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int out = sol.fib(4);
     cout<<out<<endl;
    return 0;
}