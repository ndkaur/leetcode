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


// floyd warshall algo 
// Time complexity: O(N*N*N)
// Space complexity: O(N*N)
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> grid(n+1, vector<int>(n+1,1000));
        // filling the grid 
        // 1-> 2 is a path , 2->3 is a path so , i->i+1 is a path
        for(int i=0; i<n; i++){
            grid[i][i+1] = 1;
            grid[i+1][i] = 1;
        }
        // one extra path from x to y 
        grid[x][y] = 1;
        grid[y][x] = 1;

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    grid[i][j] = min(grid[i][j] , grid[i][k]+grid[k][j]);
                }
            }
        }

        // after this grid will be filled from each node to each other node shortest distance 
        vector<int> ans(n);
        // now we need to find the number of paths using k=1 , 2, 3..n
        //  k= those paths that can be reached with traveling distance k 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i!=j){
                    int val = grid[i][j]; // dist from i to j 
                    // adding the no of times same dist is used 
                    //  eg 1->2 = 4 
                    //  ans[4-1] = ans[3] =1;
                    ans[val-1]++; // 0 base indexing 
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}