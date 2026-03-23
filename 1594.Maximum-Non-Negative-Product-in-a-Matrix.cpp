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
    long long mod = 1e9+7;

    pair<long long, long long> f(int i, int j, vector<vector<int>>& grid, vector<vector<pair<long long, long long>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m)
            return {LLONG_MAX, LLONG_MIN};

        pair<long long, long long> p ={-5,5};

        if(dp[i][j]!=p)
            return dp[i][j];

        if(i==n-1 && j==m-1){
            return {grid[i][j], grid[i][j]};
        }

        auto r = f(i, j+1, grid, dp);
        auto d = f(i+1, j, grid, dp);

        long long dmn = d.first;
        long long dmx = d.second;
        long long rmn = r.first;
        long long rmx = r.second;

        long long mn = 0;
        long long mx = 0;

        if(grid[i][j]<0){
            mn = grid[i][j] * max(rmx, dmx);
            mx = grid[i][j] * min(rmn, dmn);
        }
        else{
            mn = grid[i][j] * min(rmn, dmn);
            mx = grid[i][j] * max(rmx, dmx);
        }

        return dp[i][j] = {mn, mx};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m, {-5,5}));
        
        auto ans = f(0,0,grid, dp).second; // max val 
        return ans<0 ? -1: ans%mod;
    }
};


int main(){

    return 0;
}