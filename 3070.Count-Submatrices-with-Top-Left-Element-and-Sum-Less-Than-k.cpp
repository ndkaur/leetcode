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


class Solution0 {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(i >= 1) grid[i][j] += grid[i-1][j];
                if(j >= 1) grid[i][j] += grid[i][j-1];
                if(i >=1 && j >=1) grid[i][j] -= grid[i-1][j-1];
                if(grid[i][j] <= k) ans++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        // prefix sum row wise , col wise
        int  n= grid.size();
        int m = grid[0].size();

        // prefix sum row wise 
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                grid[i][j] += grid[i][j-1];
            }
        }

        // prefix sum col wise
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                grid[i][j] += grid[i-1][j];
            }
        }

        int ans= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]<=k)
                    ans++;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}