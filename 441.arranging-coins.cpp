/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
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

class Solution{
public:
    int arrangeCoins(long long n){
         long ans=sqrt(1+8*n) -1;
         ans=ans/2;
         return ans;
    } 
};

class Solution {
public:
    int arrangeCoins(int n) {
        long long x=sqrt(2*(long long)n);
        long long sum= x*(x+1)/2;
        if(sum>n)
            return x-1;
        return x;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n=5;
    int x=sol.arrangeCoins(n);
    cout<<x;
    return 0;
}