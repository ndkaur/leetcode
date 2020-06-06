#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vi roow,cool;

        for(int i=0;i<m;i++){
            int mn=matrix[i][0];
            for(int j=1;j<n;j++){
                if(matrix[i][j]<mn)
                    mn=matrix[i][j];
            }
            roow.push_back(mn);
        }
        // print(roow);

        for(int i=0;i<n;i++){
            int mx=matrix[0][i];
            for(int j=0;j<m;j++){
                if(matrix[j][i]>mx)
                    mx=matrix[j][i];
            }
        cool.push_back(mx);
        }
        // print(cool);
        
        vi ans;
        for(auto rel: roow){
            for(auto cel: cool){
                if(rel==cel)
                    ans.push_back(rel);
            }
        }
        return ans;
     }
};



int main(){
    Solution sol;
    vector<vector<int>> matrix; //={{3,7,8},{9,11,13},{15,16,17}};
    matrix  = {{76618,42558,65788,20503,29400,54116}};
    vi ans = sol.luckyNumbers(matrix);
    print(ans);

    return 0;
}
// @lc code=end

