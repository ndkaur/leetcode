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


class Solution { //O(n*m)
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr.push_back(grid[i][j]);
            }
        }   
        int sz = n*m;

        vector<long long> pref(sz,1), suf(sz,1);

        for(int i=1; i<sz; i++){
            pref[i] = (pref[i-1]*arr[i-1])%mod;
        }
        for(int i=sz-2; i>=0; i--){
            suf[i] = (suf[i+1]*arr[i+1])%mod;
        }
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i=0; i<sz; i++){
            long long val = (pref[i] * suf[i]) % mod;
            ans[i/m][i%m] = val;
        }
        return ans;
    }
};

// finding preofix product then diving by curr num will lead to runtime error as the size of value get too large even for long long to handle it 

int main(){

    return 0;
}