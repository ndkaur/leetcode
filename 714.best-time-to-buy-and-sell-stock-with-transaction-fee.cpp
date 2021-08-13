/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
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
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int>hold(n,0);
        vector<int> sell(n,0);
        hold[0]=-prices[0];
        for(int i=1;i<n;i++){
            // hold or buy 
            hold[i]=max(hold[i-1],sell[i-1]-prices[i]);
            sell[i]=max(sell[i-1],hold[i-1]+prices[i]-fee);
        }
        return sell[n-1];
    }
};
// same as above 
class Solution1 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<int> buy(n+1,0);
        vector<int> sell(n+1,0);
        buy[0]=-prices[0];
        for(int i=1;i<n;i++){
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
            sell[i] = max(sell[i-1], prices[i]+buy[i-1]-fee);
        }
        return sell[n-1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n<2) return 0;
        int sell=0;
        int hold=-prices[0];
        for(int i=1;i<n;i++){ 
            hold=max(hold,sell-prices[i]);
            sell=max(sell,hold+prices[i]-fee);
        }
        return sell;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> prices={1,3,2,8,4,9};
    int fee=2;
    int ans= sol.maxProfit(prices,fee);
    cout<<ans;  
    return 0;
}