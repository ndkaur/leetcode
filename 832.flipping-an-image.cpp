/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int a=A.size();
        int b=A[0].size();
        for(int i=0;i<a;i++){
            for(int j=0;j<b/2;j++){
                // for flipping/swaping
                swap(A[i][j],A[i][b-1-j]);
            }
            // for inverting
            for(int j=0;j<b;j++){
                A[i][j]^=1;
            }
        }
        return A;
        }
    };
// @lc code=end

int main(){
    Solution sol;
    vector<vi> A, out;
    A={{1,1,0},{1,0,1},{0,0,0}};
    out=sol.flipAndInvertImage(A);
    for(auto o: out){
        print(o);
    }
    return 0;
}

