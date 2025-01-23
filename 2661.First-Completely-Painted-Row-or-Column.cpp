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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // val ->{row,col}
        unordered_map<int, pair<int,int>> mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        vector<int> r(n,m); // filling it at beging with value then reducing it as the same number occurs 
        vector<int> c(m,n);

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            auto [rowidx,colidx] = mp[val];
            r[rowidx]--;
            c[colidx]--;

            if(r[rowidx]==0 || c[colidx]==0){
                return i;
            }
        }
        return -1;
        
    }
};


int main(){

    return 0;
}