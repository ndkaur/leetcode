/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        vector<pair<int,int>> vone;
        vector<int> weakrow; 
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)
                    count++;
            }
            vone.push_back({count,i});
        }
        sort(vone.begin(),vone.end()); 
        
        for(int i=0;i<k;i++){
             weakrow.push_back(vone[i].second);
        }
        return weakrow;
    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>>mat={{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}}; 
    vector<int> weakrow;
    weakrow=sol.kWeakestRows(mat,3);
    print(weakrow);
    return 0;
}
