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
class Solution {
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
// @lc code=end


int main(){
    Solution sol;
    vector<int> prices={3,3,5,0,0,3,1,4};
    int ans=sol.maxProfit(prices);
    cout<<ans;
    return 0;
}