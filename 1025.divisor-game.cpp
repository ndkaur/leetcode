/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
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
    bool divisorGame(int N) {
        if(N%2==0)
            return true;
        else 
            return false;
    }
};

class Solution1 {
    vector<int> dp;
public:
    bool divisorGame(int n) {
        dp = vector<int>(n+1,-1);
        return canwin(n);
    }
    bool canwin(int n){
        if(n<=1) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n]=0; // alex loose 
        for(auto div: getdivisor(n)){
            if(!canwin(n-div))
                return dp[n]=1;
        }
        return dp[n]=0;
    }

    vector<int> getdivisor(int n){
        if(n<=1) return {};
        vector<int> out={1};
        for(int d=2; d*d<n ;d++){
            if(n%d==0){
                int d2 = n/d;
                out.push_back(d);
                if(d!=d2)  // 5*5 =25 same factor
                    out.push_back(d2);
            }
        }
        return out; 
    }
};

class Solution {
    vector<int> dp;
public:
    bool divisorGame(int n) {
       dp= vector<int>(n+1,-1);
       return canwin(n);
    }
    bool canwin(int n){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<n;i++){
            if(n%i==0){ // factor 1
                if(canwin(n-i)==0)
                    return dp[n]=1;
            }
        }
        return dp[n]=0;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n=5;
    bool ans=sol.divisorGame(n);
    cout<<ans;
    return 0;
}