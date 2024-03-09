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

class Solution { //O(sqrt(N))
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(n>0){
            i++;
            n = n-i;
        }
        return i-1;
    }
};

class Solution{
public:
    int arrangeCoins(long long n){
         long ans=sqrt(1+8*n) -1;
         ans=ans/2;
         return ans;
    } 
};

class Solution{
public:
    int arrangeCoins(long long n){
        int l=0,r=n;
        long coin,k;
        while(l<=r){
            //k(k+1)/2<=n
            k=l+(r-l)/2;
            coin=k*(k+1)/2;
            if(coin==n)
                return k;
            if(coin>n)
                r=k-1;
            else
                l=k+1;
        }
        return r;
    } 
};

class Solution { //O(logN)
public:
    int arrangeCoins(int n) {
        long l=0;
        long r = n;
        while(l<=r){
           long mid = l+(r-l)/2;
            long used = mid * (mid+1)/2;
            if(used==n)
                return (int)mid;
            if(used<n){
                l = mid+1;
            }
            else 
                r = mid-1;
       }
       return (int) r;
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
    int n=8;
    int x=sol.arrangeCoins(n);
    cout<<x;
    return 0;
}