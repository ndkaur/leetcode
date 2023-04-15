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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans;
        for(int j=0; j<m; j++){
            int len = 0;
            for(int i=0; i<n; i++){
                int cnt =0;
                // if(grid[i][j]<0)
                //     cnt +=1;
                string num = to_string(grid[i][j]);
                cnt+= num.size();
                len = max(len,cnt);
            }
            ans.push_back(len);
        }
        return ans;
    }
};

int main(){

    return 0;
}