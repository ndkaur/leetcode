/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
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
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n+1 ,vector<int>(k+1,-1));
        sort(events.begin(), events.end());
        vector<int> start;
        for(int i=0; i<n; i++){
            start.push_back(events[i][0]);
        }
        return solve(0, start, k, events, dp);
    }
    int solve(int idx, vector<int>& start, int k, vector<vector<int>>& events, vector<vector<int>>& dp){
        int n = events.size();
        if(idx>=n || k==0)
            return 0; 
        if(dp[idx][k]!=-1)
            return dp[idx][k];

        int npick = solve(idx+1, start, k, events, dp);
        
        int end = events[idx][1];
        // ub = elem > target 
        int ub = upper_bound(start.begin(), start.end(), end) - start.begin();
        int pick = events[idx][2] + solve(ub, start, k-1, events, dp);
        
        
        return dp[idx][k] = max(npick, pick);
    }
};

// @lc code=end


int main(){

    return 0;
}