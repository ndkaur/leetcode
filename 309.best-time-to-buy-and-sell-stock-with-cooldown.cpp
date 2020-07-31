/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int A=0;
        int B= -prices[0];
        int C =0;
        for(int i=1;i<prices.size();i++){
            int temp =A;
            A= max(A,C);
            C= B+prices[i];
            B= max(B,temp-prices[i]);
        }
        return max(A,C);
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> prices={2};
    int ans=sol.maxProfit(prices);
    cout<<ans;
    return 0;
}
