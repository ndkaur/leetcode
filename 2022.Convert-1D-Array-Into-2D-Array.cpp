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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(sz!=m*n)
            return {};

        vector<vector<int>> ans(m);
        // filling the rows 
        for(int i=0; i<m; i++){
           ans[i].assign(original.begin()+i*n , original.begin()+(i+1)*n);
        }
        return ans;
    }
};

int main(){

    return 0;
}