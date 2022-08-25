/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
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
// time (N! * N) 
// space O(N^2) 
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // vector<string> board(n,string(n,'.'));
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]= s;
        }
        solve(0, board, ans, n);
        return ans;
    }
    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        // base condition
        if(col==n){
            ans.push_back(board);
            return;
        }
        // for each col we are checking each row 
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board,n)){
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                // backtrack
                board[row][col]= '.';
            }
        }
    }
    
    bool isSafe(int row, int col, vector<string> board, int n){
        int duprow= row;
        int dupcol= col;
        // check upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        // check row
        row= duprow;
        col= dupcol;
        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        // check lower diagonal
        row= duprow;
        col= dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
};


// @lc code=end


int main(){
    Solution sol;
    int n=4;
    vector<vector<string>> ans=sol.solveNQueens(n);
    for(auto x:ans){
        cout<<endl;
        for(auto y:x){
            cout<<y<<endl;
        }
    }
    return 0;
}