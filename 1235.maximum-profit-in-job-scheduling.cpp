/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
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
class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        vector<vector<int>> jobs(n,vector<int>(3));
        
        for(int i=0; i<n; i++){
            jobs[i][0] = st[i];
            jobs[i][1] = et[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        sort(st.begin(), st.end());        
        vector<int> dp(n,-1);

        return solve(0, jobs, st, dp);
    }
    int solve(int idx, vector<vector<int>>& jobs, vector<int>& st,vector<int>& dp){
        int  n = jobs.size();
        
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        int notPick = solve(idx+1, jobs, st, dp);
        // we can pick same idx after its end time to start next job so lb
        // finding the lb for the end time of the same idx  
        int end = jobs[idx][1];
        int lb = lower_bound(st.begin(), st.end(), end) - st.begin();
        int pick = jobs[idx][2] + solve(lb, jobs, st, dp);

        return dp[idx] = max(pick, notPick);
    }
};
// @lc code=end


int main(){

    return 0;
}