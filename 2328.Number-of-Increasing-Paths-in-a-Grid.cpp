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


// Time Complexity : O(NM)
// Space Complexity : O(NM)
class Solution {
public:
    int mod = 1000000007;
    int dp[1000][1000] = {};
    int countPaths(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        int cnt =0;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                // i , j, prev len indexes , grid 
                cnt = (cnt%mod + dfs(i, j, 0, grid)%mod) % mod;
            }
        }
        return cnt;
    }
    int dfs(int i, int j, int prevlen , vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        
        if(min(i,j) < 0 || i>=n || j>=m || prevlen >= grid[i][j]){
            return 0;
        }
        
        return dp[i][j]  ?  :  dp[i][j] = ( 1LL + dfs(i-1, j, grid[i][j], grid) + dfs(i, j-1, grid[i][j], grid) + 
            dfs(i+1, j, grid[i][j] , grid) + dfs(i, j+1, grid[i][j] , grid) ) % mod;
    }
};



int main(){

    return 0;
}