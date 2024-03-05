/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
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


// memo 
class Solution {
public:
    int f(int idx, vector<int>& days, vector<int>& costs, vector<int>& dp){
        int n= days.size();
        if(idx>=n)
            return 0;

        if(dp[idx]!=-1)
            return dp[idx];
            
        int one = costs[0] + f(idx+1, days, costs, dp);
        
        // seven
        int i;
        for(i=idx; i<n && days[i]<days[idx]+7; i++);
        int seven = costs[1] + f(i, days, costs, dp);

        // thirty
        for(i=idx; i<n && days[i]<days[idx]+30; i++);
        int thirty = costs[2] + f(i, days, costs, dp);

        return dp[idx] = min({one, seven, thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return f(0, days, costs, dp);
    }
};



class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int one = costs[0] + dp[i+1];
        
            // seven
            int j;
            for(j=i; j<n && days[j]<days[i]+7; j++);
            int seven = costs[1] + dp[j];

            // thirty
            for(j=i; j<n && days[j]<days[i]+30; j++);
            int thirty = costs[2] + dp[j];

            dp[i] = min({one, seven, thirty});
        }

        return dp[0];
    }
};




// @lc code=end


int main(){
    Solution sol;
    vector<int> d= {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> c ={2,7,15};
    int ans = sol.mincostTickets(d, c);
    cout<<ans;
    return 0;
}