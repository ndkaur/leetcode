/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
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
class Solution0 {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int i=0;
        int peak= prices[0];
        int low = prices[0];
        int mx=0;

        while(i<n-1){
            while(i<n-1 && prices[i]>=prices[i+1]) 
                i++;
            low =prices[i];
            while(i<n-1 && prices[i]<=prices[i+1])
                i++;
            peak=prices[i];
            mx=mx+peak-low;
        }
        return mx;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int mx=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
                mx+= prices[i]-prices[i-1];
        }
        return mx;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    int m =sol.maxProfit(prices);
    cout<<m;
    return 0;
}