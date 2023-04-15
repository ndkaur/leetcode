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

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        // dp[size of arrays][value of k ]
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        // making the array as prefix sum array 
        // (1,100,3) = (1,101,104)
        for(int i=0; i<n; i++){
            for(int j=1; j<piles[i].size(); j++){
                piles[i][j] = piles[i][j-1]+piles[i][j];
            }
        }
        return solve(piles,k,0,dp);
    }
    int solve(vector<vector<int>>& piles, int k, int i, vector<vector<int>>& dp){
        int n = piles.size();
        int m = piles[0].size();
        // base condition when k is finsihed 
        // when i is out of index
        if(i>=n)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int mx =0;
        // if we dont pick and move to next array
        mx = max(mx, solve(piles,k, i+1, dp));
        for(int j=0; j<piles[i].size(); j++){
            // pick current idx from the pile and move ahead if k availabe 
            if(j+1<=k){
                // keep on picking coins from same pile till k vanishes to 0 
                mx= max(mx, piles[i][j]+solve(piles, k-j-1, i+1, dp));
            }
            else    
                break;
        }
        return dp[i][k] = mx;
    }
};


class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int m = piles[0].size();
        // dp[size of arrays][value of k ]
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));

        return solve(piles,0,k,dp);
    }
    int solve(vector<vector<int>>& piles, int i, int k, vector<vector<int>>& dp){
        int n = piles.size();
        // base condition when k is finsihed 
        // when i is out of index
        if(i==n || k==0)
            return 0;
        if(dp[i][k]>0)
            return dp[i][k];

        // if we dont pick and move to next array
        int res = solve(piles,i+1,k, dp);
        int curr =0;

        for(int j=0; j<piles[i].size() && j<k; j++){
            curr += piles[i][j]; // making the prefix sum 
          // keep on picking coins from same pile till k vanishes to 0 
            res = max(res, curr+ solve(piles,i+1, k-j-1, dp));
        }
        dp[i][k] = res;
        return res;
    }
};


int main(){

    return 0;
}