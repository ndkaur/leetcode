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
    int mod = 1e9+7;
    int f(int i, int j, int sum, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i==n || j==m)
            return 0;

        if(i==n-1 && j==m-1){
            if((sum+grid[i][j])%k==0){
                return 1;
            }
            else 
                return 0;
        }

        if(dp[i][j][sum]!=-1)
            return dp[i][j][sum];
        
        return dp[i][j][sum]  = (f(i+1, j, (sum+grid[i][j])%k ,grid, k, dp) + f(i, j+1, (sum+grid[i][j])%k, grid, k, dp))%mod;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1,-1)));

        return f(0,0,0,grid, k,  dp);
    }
};

int main(){

    return 0;
}