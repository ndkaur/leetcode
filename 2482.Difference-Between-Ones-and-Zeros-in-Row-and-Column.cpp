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
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowOne(n);
        vector<int> colOne(m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rowOne[i] += grid[i][j];
                // col[0] += grid[0][0] + grid[1][0] + grid[2][0]
                // col[1] = grid[0][1] + grid[1][1] + grid[2][1]
                colOne[j] += grid[i][j];
            }
        }
        // for(int r:rowOne){
        //     cout<<r<<" ";
        // }
        // cout<<endl;
        // for(int c:colOne){
        //     cout<<c<<" ";
        // }
        // no of zero = total size - no of ones 
        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // int res = (rowOne[i]) + (colOne[j]) - (n-rowOne[i]) - (m-colOne[j]);
                int res = 2*rowOne[i] + 2*colOne[j] - n -m;
                ans[i][j] = res;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}