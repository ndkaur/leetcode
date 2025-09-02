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

class Solution0 { // O(n*m)
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n));
        if(m*n!=original.size())
            return {};
        int idx =0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = original[idx];
                idx++;
            }
        }
        return ans;
    }
};


class Solution { // O(n)
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int rows, int cols) {
        vector<vector<int>> ans(rows, vector<int>(cols));
        if(rows*cols!=original.size())
            return {};
       
        for(int i=0; i<rows*cols; i++){
            ans[i/cols][i%cols] = original[i];
        }
        return ans;
    }
};



int main(){

    return 0;
}