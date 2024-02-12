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


class Solution { //O(4*m*n)~ O(m*n)
public:
    int mod = 1e9+7;
    int dfs(int i, int j, vector<pair<int,int>>& dirs,  vector<vector<int>>& dp, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int len = 1;

        if(dp[i][j]!=-1)
            return dp[i][j]; 

        for(auto dir:dirs){
            int nx = i+dir.first;
            int ny = j+dir.second;
            if(nx>=0 && nx<n && ny>=0 && ny<m &&  grid[i][j]<grid[nx][ny]){
                len  = (len + dfs(nx, ny, dirs, dp,grid))%mod;
            }
        }
        return dp[i][j] = len;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        vector<pair<int,int>> dirs = {{0,1},{-1,0},{0,-1},{1,0}};
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cnt= (cnt+ dfs(i, j, dirs, dp, grid))%mod;
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}