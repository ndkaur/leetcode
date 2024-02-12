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
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j=0; j<m; j++){
            int mx =0;
            for(int i=0; i<n; i++){
                mx = max(mx, matrix[i][j]);
            }
            for(int i=0; i<n; i++){
                if(matrix[i][j]==-1)
                    matrix[i][j] = mx;
            }
        }
        return matrix;
    }
};

int main(){

    return 0;
}