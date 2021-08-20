/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col= matrix[0].size();
        int ans =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i && j && matrix[i][j]){
                    matrix[i][j]+= min({matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]});
                }
            ans+= matrix[i][j];
            }
        }
        return ans;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    int ans = sol.countSquares(matrix);
    cout<<ans;
    return 0;
}