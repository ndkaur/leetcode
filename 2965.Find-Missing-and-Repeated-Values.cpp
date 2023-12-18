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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int,int> mp;
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                mp[grid[i][j]]++;
            }
        }
        int a,b;
        for(int i=1; i<=n*n; i++){
            if(mp.find(i)==mp.end()){
                b= i;
            }
            if(mp[i]>1){
                a=i;
            }
        }
        return {a,b};
    }
};

int main(){

    return 0;
}