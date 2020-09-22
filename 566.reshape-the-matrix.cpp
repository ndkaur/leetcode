/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
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
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        // row will change when col is filled
        int n=nums.size();
        int m= nums[0].size();
        if(n==0 || r*c!=n*m) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        int row=0,col=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[row][col]=nums[i][j];
                col++;
                if(col==c){
                    row++;
                    col=0;
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> nums={{1,2},{3,4}};
    int r=2;
    int c=4;
    vector<vector<int>> ans=sol.matrixReshape(nums,r,c);
    for(auto x:ans){
        print(x);
    }
    return 0;
}