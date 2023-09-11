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
    // vector<vector<int>> dirs= {{0,-1},{-1,0},{0,1},{1,0}};
    int minimumMoves(vector<vector<int>>& grid) {
        return solve(grid);
    }
    int solve(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        int zero =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0)
                    zero++;
            }
        }

        if(zero==0)
            return 0;
        int cnt = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    // then consider taking 1 from all the indexes
                    for(int row=0; row<n; row++){
                        for(int col=0; col<m; col++){
                            if(grid[row][col]>1){
                                int moves = abs(row-i)+abs(col-j);
                                grid[row][col]--; // we taking values from new idx
                                grid[i][j]++; // i, j is zero make it 1
                                
                                cnt = min(cnt, moves+solve(grid));
                                // backtrack
                                grid[row][col]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}