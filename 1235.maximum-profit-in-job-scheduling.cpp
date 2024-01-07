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
    int f(int idx, vector<vector<int>>& jobs, vector<int>& dp, vector<int>& st){
        int n = dp.size();

        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];

        // not pick then move to next index
        int npick =  f(idx+1, jobs, dp, st);
        // pick the curr idx add its profit and find tht next index that we should go to , one condition is we can start from same place where we ended 
        int end = jobs[idx][1]; 
        // we need to find the next start time for the last end time used
        int lb = lower_bound(st.begin(), st.end(), end) - st.begin();
        // pick then add profit of curr idx and move to next indx
        int pick = jobs[idx][2] + f(lb, jobs, dp, st);

        return dp[idx] = max(pick, npick);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        // if we sort the start then the corresponding order of it with end and profit will change so we need to store all three of them at one place 
        vector<vector<int>> jobs(n, vector<int>(3));
        for(int i=0; i<n; i++){
            jobs[i][0] = st[i];
            jobs[i][1] = et[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        // sort the start time also 
        sort(st.begin(), st.end());
        // we need to store the previous profits made so use dp
        vector<int> dp(n,-1);
        return f(0,jobs, dp, st);
    }
};

// @lc code=end


int main(){

    return 0;
}