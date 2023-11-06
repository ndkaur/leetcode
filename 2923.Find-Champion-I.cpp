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
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    mp[i]++;
                }
            }
        }
        int ans;
        int mx = 0;
        for(auto itr:mp){
            if(itr.second>mx){
                mx = itr.second;
                ans = itr.first;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}