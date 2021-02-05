/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
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

class Solution {
public:
    int totalNQueens(int n) {
       int ans = 0;
       vector<string> board(n,string(n,'.'));
       help(ans,board,n,0);
       return ans;
    }
    void help(int &ans, vector<string> & board,int &n,int row){
        if(row==n)
            ans++; // reached end and placed queens
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

// @lc code=start

// @lc code=end


int main(){
    Solution sol;
    int n =4;
    int ans= sol.totalNQueens(n);
    cout<<ans;
    return 0;
}