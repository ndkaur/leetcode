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
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                if(grid[i][j] > grid[i-1][j]) // already increasing order
                    continue;
                int prev_val = grid[i-1][j]+1;
                cnt += prev_val-grid[i][j];
                grid[i][j] = prev_val;
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}