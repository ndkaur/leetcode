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