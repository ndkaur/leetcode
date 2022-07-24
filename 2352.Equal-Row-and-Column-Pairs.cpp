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
    int equalPairs(vector<vector<int>>& grid) {

        vector<vector<int>> col;
        for(int j=0;j<grid[0].size();j++){
            vector<int> temp;
            for(int i=0;i<grid.size();i++){
                temp.push_back(grid[i][j]);
            }
            col.push_back(temp);
        }
        int cnt=0;
        for(auto r:grid){
            for(auto c:col){
                if(check(r,c))
                    cnt++;
            }
        }
        return cnt;
    }

    bool check(vector<int>& r, vector<int>& c){
        for(int i=0;i<r.size();i++){
            if(r[i]!=c[i])
                return false;
        }
        return true;
    }
};


class Solution1 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        int n= grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    // row, col == col row
                    if(grid[i][k]!=grid[k][j])
                        break;
                    if(k==n-1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        map<vector<int>, int> mp;
        for(int i=0;i<grid.size();i++){
            mp[grid[i]]++;
        }

        for(int j=0;j<grid[0].size();j++){
            vector<int> temp;
            for(int i=0;i<grid.size();i++){
                temp.push_back(grid[i][j]);
            }
            ans += mp[temp];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid= {{3,2,1},{1,7,6},{2,7,7}};
    int ans= sol.equalPairs(grid);
    cout<<ans;
    return 0;
}