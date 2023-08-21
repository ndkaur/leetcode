/*
 * @lc app=leetcode id=2008 lang=cpp
 *
 * [2008] Maximum Earnings From Taxi
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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int sz = rides.size();
        sort(rides.begin(), rides.end());
        vector<int> start;
        for(int i=0; i<sz; i++){
            start.push_back(rides[i][0]);
        }
        vector<long long> dp(100005,-1);
        return solve(0, start, dp, rides);
    }
    long long solve(int idx, vector<int>& start, vector<long long>& dp, vector<vector<int>>& rides){
        int n= rides.size();
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        long long npick = solve(idx+1, start, dp, rides);
        // can take next reide as the curr ends
        long long lb = lower_bound(start.begin(), start.end(), rides[idx][1])- start.begin();
        
        long long pick = rides[idx][1] - rides[idx][0] + rides[idx][2] + solve(lb, start, dp, rides);

        return dp[idx] = max(pick, npick); 
    }
};


// @lc code=end


int main(){

    return 0;
}