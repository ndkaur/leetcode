/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
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
class Solution0 { // O(n*m)*(n*m)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    for(int r=0; r<n; r++){
                        vis[r][j]=0;
                    }
                    for(int c=0; c<m; c++){
                        vis[i][c] =0;
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = vis[i][j];
            }
        }
    }
};

// using set
class Solution { // O(n*m)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();

        unordered_set<int> row;
        unordered_set<int> col;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row.count(i)>0 || col.count(j)>0)
                    matrix[i][j] = 0;
            }
        }
    }
};
// @lc code=end


int main(){

    return 0;
}