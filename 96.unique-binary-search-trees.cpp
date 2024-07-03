/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
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
class Solution0 { // O(3^n)
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        int ans= 0;
        for(int i=1; i<=n; i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }
        return ans;
    }
};

// dp memeoization 
class Solution1 { // O(N^2)
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.resize(n+1);
        if(n<=1)
            return 1;
        if(dp[n])
            return dp[n];
        for(int i=1; i<=n; i++){
            dp[n] += numTrees(i-1) * numTrees(n-i);
        }
        return dp[n];
    }
};


class Solution { //O(N*N)
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;

        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

// catalan numbers :- 1,1,2,5,14,42,132,429,1430,




//  binomial cofficent  2n C n / n+1 
//  property nCr = nC n-r
class Solution {
public:
    long cal(int n , int k){
        long ans=1;
        if(k>n-k)
            k= n-k; // property
        for(int i=0;i<k;i++){
            ans*= (n-i);
            ans/= (i+1);
        }
        return ans;
    }
    int numTrees(int n) {
        return cal(2*n, n) / (n+1); 
        //  to calculate 2n C n
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n =3;
    int ans= sol.numTrees(n);
    cout<<ans;
    return 0;
}