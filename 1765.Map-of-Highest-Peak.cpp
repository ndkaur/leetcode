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


// multi-directional bfs 
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n==0)
            return mat;
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        // distance of nearest 1 from current cell
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto dir:dirs){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(ans[nr][nc]>ans[r][c]+1){
                        ans[nr][nc] = ans[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}