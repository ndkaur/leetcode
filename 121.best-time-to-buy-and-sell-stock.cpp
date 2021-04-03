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
class Solution1 {
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


class Solution0 {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int mx_profit=0;
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
               int  profit = prices[j]-prices[i];
               if(profit>mx_profit)
                    mx_profit=profit;
           }
       }
       return mx_profit;
    } // o(n2)
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx_profit=0;
        int min_price =INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i]<min_price)
                min_price=prices[i];
            else if(prices[i]-min_price>mx_profit)
                mx_profit=prices[i]-min_price;
        }
        return mx_profit;
    } //o(n)
};
// @lc code=end
             

int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    int max_profit=sol.maxProfit(prices);
    cout<<max_profit;
    return 0;
}