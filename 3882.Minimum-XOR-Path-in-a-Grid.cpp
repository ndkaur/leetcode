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
    int f(int i, int j, int val, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int n, int m){
        if(i==n-1 && j==m-1)
            return grid[i][j]^val;

        if(dp[i][j][val]!=-1)
            return dp[i][j][val];
        int ans = 1e9;

        if(i+1<n) // down  
            ans = min(ans, f(i+1, j, val^grid[i][j], grid, dp, n, m));
        if(j+1<m) // right
            ans = min(ans, f(i, j+1, val^grid[i][j], grid, dp, n, m));
        
        return dp[i][j][val] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1025,-1)));
        return f(0,0,0, grid, dp, n,m);
    }
};


int main(){

    return 0;
}