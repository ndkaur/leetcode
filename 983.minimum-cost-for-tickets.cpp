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

class Solution0 {
public:
    int help(vector<int>& days, vector<int>& costs, int stidx){
        int n = days.size();
        if(stidx >= n) return 0;
        int cost1 = costs[0] + help(days, costs, stidx+1);
        int cost2=0, cost3=0;
        for(int i = stidx ; i<n && days[i]<days[stidx]+7;i++)
            cost2 = costs[1] + help(days, costs , i);
        for(int i=stidx ; i<n && days[i]<days[stidx]+30 ; i++)
            cost3 = costs[2]+ help(days, costs , i);
        return min({cost1,cost2,cost3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        int ans = help(days, costs, 0);
        return ans;
    }
}; 

// bottom up approach 
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--){
            int d7=i,d30=i;
            while(d7<n && days[d7]<days[i]+7)
                d7++;
            while(d30<n && days[d30]< days[i]+30)
                d30++;
            dp[i] = min ({costs[0]+dp[i+1], costs[1]+dp[d7] , costs[2]+dp[d30] });
        }
        return dp[0];
    }
}; 
// @lc code=end


int main(){
    Solution sol;
    vector<int> days= {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs ={2,7,15};
    int ans = sol.mincostTickets(days, costs);
    cout<<ans;
    return 0;
}