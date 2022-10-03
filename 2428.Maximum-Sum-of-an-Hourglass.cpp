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
    int maxSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int mx = INT_MIN;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
               int sum = grid[i][j] + grid[i][j+1]+ grid[i][j+2]+ grid[i+1][j+1]+ grid[i+2][j] +grid[i+2][j+1]+grid[i+2][j+2];
                mx = max(sum, mx);
            }
        }
        return mx;
    }
};



int main(){

    return 0;
}