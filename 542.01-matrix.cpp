/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */
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


// @lc code=start

// same as rotten oranges 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0)
            return mat;
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] ==0 ){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        vector<vector<int>> dirs ={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto dir:dirs){
                int nrow = r + dir[0];
                int ncol = c+ dir[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    // if its not a 0 then in ans its marked as INT_MAX
                    // valid points  -> INT_MAX > 0+1 yes so replace ans = 1
                    if(ans[nrow][ncol] > ans[r][c] + 1){
                        ans[nrow][ncol] = ans[r][c] +1;
                        q.push({nrow,ncol});
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


// @lc code=end

