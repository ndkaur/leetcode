/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=A[j][i];
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> A={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans=sol.transpose(A);
    for(auto x:ans){
        print(x);
    }
    return 0;
}