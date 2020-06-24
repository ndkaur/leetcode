/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) 
            return 0;
        int max_price=prices[n-1];
        int max_profit=0;
        for(int i=n-2;i>=0;i--){
            int cur_profit=max_price-prices[i];
            max_profit=max(max_profit,cur_profit);
            max_price= max(max_price,prices[i]);
        }
        return max_profit;
    }
};
// @lc code=end
             

int main(){
    Solution sol;
    vector<int> prices={1,2};
    int max_profit=sol.maxProfit(prices);
    cout<<max_profit;
    return 0;
}