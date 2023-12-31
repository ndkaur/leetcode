/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
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


// a,b,c,d
// max(a) + bcd  , max(a,b) + cd,   max(a,b,c) + d
// max(a)+max(b)+max(c,d) 
// so the process is chooses a subarray take its max + calculate for the remaining subarry in between d limit of days

class Solution {
public:
    int dfs(int idx, int d, vector<int>& jobs, vector<vector<int>>& dp){
        int n = jobs.size();
        // base condtion
        if(idx==n && d==0) // reached array end and no days remaining
            return 0;
        if(idx==n || d==0 || n-idx<d) // days still remaining but we dont have jobs size left
            return 1e9;

        if(dp[idx][d]!=-1)
            return dp[idx][d];
        
        int ans = 1e9;
        int mx = -1e9;
        // max from one subarray  +  calculate for the remaining subarray in the remaining d days
        for(int i=idx; i<n; i++){
            mx = max(mx, jobs[i]);
            ans = min(ans, mx + dfs(i+1, d-1, jobs, dp));
        }

        dp[idx][d]  = ans;
        return ans;
    }
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        if(n<d) // size is less and days are more so not possible to divide it in possible subarrays
            return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        int ans = dfs(0, d, jobs, dp);
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}