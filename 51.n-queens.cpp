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
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n,string(n,'.'));
       help(ans,board,n,0);
       return ans;
    }
    void help(vector<vector<string>> &ans, vector<string> & board,int &n,int row){
        if(row==n)
            ans.push_back(board); // reached end and placed queens
        if(row>=n) // termination condition
            return ;
        
        for(int col=0;col<n;col++){ // for travesing row col changes
            if(canPlace(board,row,col,n)){
                board[row][col]='Q';
                help(ans,board,n,row+1);
                board[row][col]='.';  // backtracking
            }
        }
    }

    bool canPlace(vector<string> & board,int row, int col, int n){
        // check row 
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
                return false ;
        }
        // check left diagonal 
        int x= row;
        int y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        // check right diagonal
        x=row;
        y=col; 
        while(x>=0 && y<n){
            if(board[x][y]=='Q')
                return false ;
            x--;
            y++;
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