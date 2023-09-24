/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
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

// @lc code=end

class Solution {
public:

    double solve(int pour, int row, int glass,vector<vector<double>>&cache)
    {
        if(row <0 || glass > row || glass <0)
        {
            return 0;
        }
        if(row == 0 && glass == 0)
        {
            return pour;
        }
        if(cache[row][glass]!=-1)
        {
            return cache[row][glass];
        }

        double left = solve(pour,row-1,glass-1,cache)-1;
        if(left < 0) left=0;

        double right = solve(pour,row-1,glass,cache)-1;
        if(right < 0) right=0;

        return cache[row][glass] = (left+right)/2;

    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cache(100,vector<double>(100,-1));
        return min(1.00,solve(poured,query_row,query_glass,cache));
    }
};


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101,0.0));
        dp[0][0]= (double)poured;

        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++){
                double extra = (dp[i][j]-1.0)/2.0; // extra for curr cup
                if(extra>0){ // then divide in next two cups
                    dp[i+1][j] += extra; // below
                    dp[i+1][j+1] += extra; // diagonal
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};


int main(){

    return 0;
}