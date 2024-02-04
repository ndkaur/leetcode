/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
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
    int f(int idx, vector<int>& arr, int k){
        int n = arr.size();
        if(idx>=n) // out of bound case
            return 0;
        
        int mxSum = 0;
        int mxElem = 0;
        for(int i=idx; i<min(n, idx+k); i++){
            mxElem =  max(mxElem, arr[i]);
            // sum of a subarray = mxElem * no of elemts present int hat subarray
            mxSum = max(mxSum, mxElem * (i-idx+1) + f(i+1, arr, k));
        }
        return mxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return f(0,arr, k);
    }
};


class Solution {
public:
    int f(int idx, vector<int>& arr, int k, vector<int>& dp){
        int n = arr.size();
        if(idx>=n) // out of bound case
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];

        int mxSum = 0;
        int mxElem = 0;
        for(int i=idx; i<min(n, idx+k); i++){
            mxElem =  max(mxElem, arr[i]);
            // sum of a subarray = mxElem * no of elemts present int hat subarray
            mxSum = max(mxSum, mxElem * (i-idx+1) + f(i+1, arr, k, dp));
        }
        dp[idx] = mxSum;
        return mxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,arr, k, dp);
    }
};


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1; i>=0; i--){
            int mxSum = 0;
            int mxElem = 0;
            for(int j=i; j<min(n, i+k); j++){
                mxElem =  max(mxElem, arr[j]);
                // sum of a subarray = mxElem * no of elemts present int hat subarray
                mxSum = max(mxSum, mxElem * (j-i+1) + dp[j+1]);
            }
            dp[i] = mxSum;
        }
        return dp[0]; 
    }
};


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i=1;i<=n;++i){
            int cur= 0 , best=0;
            // i=2 , k=3 , i-k = 2-3 =-1 // negative 
            for(int k=1; k<=K && i-k >=0; ++k){
                cur = max(cur, arr[i-k]);
                best = max(best, dp[i-k]+cur*k);
            }
            dp[i]=best;
        }
        return dp[n];
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> arr= {1,4,1,5,7,3,6,1,9,9,3};
    int k =4;
    int ans= sol.maxSumAfterPartitioning(arr,k);
    cout<<ans;
    return 0;
}