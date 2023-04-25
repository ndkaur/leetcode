/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
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

// RECURSION // tle                           
class Solution {  
public:
    int mod =1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // same as knapsack pick and not pick 
        // three main things to consider:= 
        // 1) max people that we can take 
        // 2) min profit which i snow remaining
        //3) curr profit if greter than mn profit then count ++

        int ans = solve(0,n, minProfit, group, profit);
        return ans;
    }

    int solve(int idx, int mxPeople, int mnProfit, vector<int>&group, vector<int>& profit){
        if(mxPeople<0)
            return 0;
        
        if(idx==group.size()){
            // idx reached end now see 
            // if mnprofit still remaing means condition didnot meet
            // if mnprofit 0 then increse cnt of output 
            if(mnProfit >0)
                return 0;
            else    
                return 1;
        }

        int pick = solve(idx+1, mxPeople-group[idx], mnProfit-profit[idx],group, profit);
        int npick = solve(idx+1, mxPeople, mnProfit, group, profit);

        return (pick + (long long)npick) % mod;
    }
};


// top down 
class Solution {
public:
    int mod =1e9+7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // same as knapsack pick and not pick 
        // three main things to consider:= 
        // 1) max people that we can take 
        // 2) min profit which i snow remaining
        //3) curr profit if greter than mn profit then count ++
        // dp = mnProfit , mxPeople, idx-> group.size()
        vector<vector<vector<int>>> dp(minProfit+1, vector<vector<int>>(n+1,vector<int>(group.size(),-1)));
        int ans = solve(0, n, minProfit, group, profit, dp);
        return ans;
    }

    int solve(int idx, int mxPeople, int mnProfit, vector<int>&group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        if(mxPeople<0)
            return 0;
        
        if(idx==group.size()){
            // idx reached end now see 
            // if mnprofit still remaing means condition didnot meet
            // if mnprofit 0 then increse cnt of output 
            if(mnProfit >0)
                return 0;
            else    
                return 1;
        }
        // each time we gain profit we reduce profit[i] from mnProfit so it is posssible to become neg
        if(mnProfit < 0) // case like mn =5 so we pick 6+7+8 is also the scheme
            mnProfit = 0;
        
        if(dp[mnProfit][mxPeople][idx]!=-1)
            return dp[mnProfit][mxPeople][idx];

        int pick = solve(idx+1, mxPeople-group[idx], mnProfit-profit[idx],group, profit,dp);
        int npick = solve(idx+1, mxPeople, mnProfit, group, profit,dp);

        return dp[mnProfit][mxPeople][idx] = (pick + (long long)npick) % mod;
    }
};
// @lc code=end


int main(){

    return 0;
}