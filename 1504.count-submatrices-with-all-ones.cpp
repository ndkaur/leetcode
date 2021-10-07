/*
 * @lc app=leetcode id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=m-1;j>=0;j--){
                if(mat[i][j])
                    count++;
                else count=0;
                dp[i][j]= count;
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int mn =INT_MAX;
                for(int k=i;k<n;k++){
                    mn = min(mn, dp[k][j]);
                    ans += mn;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> mat ={{1,0,1},{1,1,0},{1,1,0}};
    int ans = sol.numSubmat(mat);
    cout<<ans;
   return 0;
}

// 1 0 1       dp :-    1 0 1
// 1 1 0                1 2 0   
// 1 1 0                1 2 0  