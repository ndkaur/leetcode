/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
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
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int k=2;
        vector<vector<int>> buy(k+1,vector<int>(n+1));
        vector<vector<int>> sell((k+1),vector<int>(n+1));
        for(int i=1;i<=k;i++){
            buy[i][0]=INT_MIN;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                sell[j][i] = max(sell[j][i-1],buy[j][i-1]+prices[i-1]);
                buy[j][i]= max(buy[j][i-1],sell[j-1][i-1]-prices[i-1]);
            }
        }
        return sell[k][n];
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return find(prices,0,0,1,dp);
    }
    int find(vector<int>& prices, int i, int trans ,bool buy, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(i>=n || trans>=2) return 0;
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        if(buy)
            return dp[i][buy][trans]= max(-prices[i]+find(prices,i+1,trans,!buy,dp) , find(prices,i+1,trans,buy,dp));
        else 
            return dp[i][buy][trans]= max(prices[i]+find(prices,i+1,trans+1,!buy,dp),find(prices,i+1,trans,buy,dp));
     }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int buy1=INT_MAX;
        int buy2=INT_MAX;
        int sell1=0;
        int sell2=0;
        for(int i=0;i<n;i++){
            buy1= min(buy1,prices[i]);
            sell1 = max(sell1, prices[i]-buy1);
            buy2= min(buy2,prices[i]-sell1);
            sell2= max(sell2 , prices[i]-buy2);
        }
        return sell2;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int buy1=INT_MIN;
        int buy2=INT_MIN;
        int sell1=0;
        int sell2=0;
        for(int i:prices){
            sell2= max(sell2 , i+buy2);
            buy2= max(buy2,sell1-i);
            sell1 = max(sell1, i+buy1);
            buy1= max(buy1,-i);
        }
        return sell2;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> prices={3,3,5,0,0,3,1,4};
    int ans=sol.maxProfit(prices);
    cout<<ans;
    return 0;
}