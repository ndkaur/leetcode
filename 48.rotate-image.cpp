/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}
// @lc code=start

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose ->change row into col and col into row 
        // swap cols
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            // reverse all elemts of each row one by one 
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


// @lc code=end



int main(){

    return 0;
}