/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int len =indices.size();
        // to create a matrix
        vector<vector<int>> matrix(n, vector<int>(m));
        // to trace through a matrix
        for (auto index:indices){
            // to refer row as 0th element
            int r= index[0];
            // to refer column as 1th element
            int c=index[1];
            // to trace through a row
            // row contains the elements for a column
            for (int i=0;i<n;i++){
                matrix[i][c]++;
                }
            // to trace through a cloumn
            // column contains the elements for a row
            for(int j=0;j<m;j++){
                matrix[j][r]++;
                }
        }
        // to count the no of occurance of odd nos of matrix
        int odd=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]%2!=0)
                   odd++;
            }
        }
        return odd;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> indices;
    int odd;
    int n=2,m=3;
    indices={{1,0},{0,0}};
    n = 2, m = 2;
    odd=sol.oddCells(n,m,indices);
    cout<<odd;
    return 0;
}