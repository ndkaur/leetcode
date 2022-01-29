/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
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
class Solution0 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        // checking for row   --  have to move on col
        for(int col=0;col<m;col++){
            srt(mat,0, col, m ,n );
        }
        //  checking for col -- have to move on row
        for(int row=1;row<n; row++){
            srt(mat, row, 0, m ,n);
        }
        return mat;

    }
    void srt(vector<vector<int>> &mat, int row, int col, int& m, int& n){
        vector<int> val;
        int r= row; 
        int c= col;
        while(r<n && c<m){
            val.push_back(mat[r][c]); // insert digonal val one by one in vector
            r++; 
            c++;
        }
        sort(val.begin(), val.end()); 
        // put values from vector back to matrix
        r=row;
        c=col;
        int k=0;
        while(r<n && c<m){
            mat[r][c]= val[k];
            k++;
            r++;
            c++;
        }
    }
};


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        // checking for row   --  have to move on col
        for(int col=0;col<m;col++){
            srt(mat,0, col, m ,n );
        }
        //  checking for col -- have to move on row
        for(int row=1;row<n; row++){
            srt(mat, row, 0, m ,n);
        }
        return mat;

    }
    void srt(vector<vector<int>> &mat, int row, int col, int& m, int& n){
        int r= row; 
        int c= col;
        vector<int> val(101);
        while(r<n && c<m){
            val[mat[r][c]]++; // insert digonal val one by one in vector
            r++; 
            c++;
        }
        
        // put values from vector back to matrix
        r=row;
        c=col;
        for(int k=1;k<val.size();k++){
            while(val[k]>0){
                mat[r][c]= k;
                val[k]--;
                r++;
                c++;
            }
        }
    }
};
// @lc code=end



int main(){
    Solution sol;
    vector<vector<int>> mat={{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    vector<vector<int>> ans =sol.diagonalSort(mat);
    for(auto x:ans)
        print(x);
    return 0;
}