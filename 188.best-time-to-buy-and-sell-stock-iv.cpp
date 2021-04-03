/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
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
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        if(n<2) return 0;
        if(k>n/2){
            int ans=0;
            for(int i=1;i<n;i++)
                ans+= max(prices[i]-prices[i-1],0);
            return ans;
        }
        int hold[k+1];
        int sell[k+1];
        for(int i=0;i<=k;i++){
            hold[i]=INT_MIN;
            sell[i]=0;
        }
        int curr;
        for(int i=0;i<n;i++){
            for(int j=k;j>0;j--){
                sell[j]=max(sell[j],hold[j]+prices[i]);
                hold[j]=max(hold[j],sell[j-1]-prices[i]);
            }
        }
        return sell[k];
    }
};
// @lc code=end
 

int main(){
    Solution sol;
    vector<int> prices={3,2,6,0,5,3};
    int k =2;
    int ans=sol.maxProfit(k,prices);
    cout<<ans;
    return 0;
}