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
    int f(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        int score = 0;

        // out of bound
        if(i>=n || j>=m)
            return -1e9;

        // only 1 and 2 are effecting the cost by 1 
        if(grid[i][j]==1){
            score+=1;
            k -= 1;
        }
        else if(grid[i][j]==2){
            score+=2;
            k-=1;
        }
        else{
            k-=0;
            score+=0;
        }

        if(k<0)
            return -1e9;

        if(i==n-1 && j==m-1){ // destination
            return score;
        }

        if(dp[i][j][k]!=-1)
            return dp[i][j][k];

        int r = f(i, j+1, k, grid, dp);
        int d = f(i+1, j, k, grid, dp);
        
        return dp[i][j][k] = score + max(r,d);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1,-1)));
        
        int mx = f(0,0,k,grid, dp);
        return mx<0 ? -1 :mx;
    }
};



int main(){

    return 0;
}