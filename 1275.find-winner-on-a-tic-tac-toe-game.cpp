/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

const int x = 0;
const int y = 1;

// @lc code=start
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3,vector<char>(3,'.'));
        int n=moves.size();
        string xo= "XO";
        // First step : to check whose turn it is .
        for(int i=0; i<n; ++i){
            int x_coor = moves[i][0];
            int y_coor = moves[i][1];
            if(i%2==0) // if i=0 it is even otherwise if i=1 it is odd.
                board[x_coor][y_coor] = 'X';
            else 
                board[x_coor][y_coor] = 'O';
        }

        // Second step: to check the conditions of winner,draw,pending.
        if(result('X',board))   return "A";
        else if (result('O',board)) return "B";
        if(moves.size()<9) return "Pending";
        return "Draw";        
    }

        // Third step: to check the winner conditions for diagonals ,rows,columns;
    bool result(char a, vector<vector<char>> &board ){
            //for rows
        for(int row=0;row<3;row++){
            if(board[row][0]==a && board[row][1]==a && board[row][2]==a)
                return true;
            }
            //for columns
        for(int col=0;col<3;col++){
            if(board[0][col]==a && board[1][col]==a && board[2][col]==a)
                return true;
            }
            // for diagonals
        if(board[0][0]==a && a==board[1][1] && a==board[2][2])
            return true;
        if(board[0][2]==a && board[1][1]==a && board[2][0]==a)
            return true;
            
            //if none of the above condition works then return false.
        return false;
        }
};

int main(){
    Solution sol;
    vector<vector<int>> moves={{0,0},{2,0},{1,1},{2,1},{2,2}};
    string xo;
    xo=sol.tictactoe(moves);
    cout<<xo;
    return 0;
}
// @lc code=end


