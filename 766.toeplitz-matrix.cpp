/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        int m= matrix[0].size()-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 && j>0 && matrix[i][j]!=matrix[i+1][j+1])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> matrix={{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    bool ans=sol.isToeplitzMatrix(matrix);
    cout<<ans;
    return 0;
}