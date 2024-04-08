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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<n; i++){
            reverse(image[i].begin(), image[i].end());
            for(int j=0; j<m; j++){
                image[i][j] = image[i][j]==0 ? 1 : 0;
            }
        }
        return image;
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

