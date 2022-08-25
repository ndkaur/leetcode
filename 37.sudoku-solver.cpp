/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
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
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                // empty space found
                if(board[i][j] == '.'){
                    for(char c='1'; c<='9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board) == true) // valid then move ahead 
                                return true;
                            else 
                                board[i][j]= '.'; // backtracking
                        }
                    }
                    // if not able to plave any 1-> 9
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            // check row 
            if(board[i][col] == c)
                return false;
            // check col
            if(board[row][i] == c)
                return false;
            // check box 
            if(board[3*(row/3)+ i/3][3*(col/3) + i%3] == c)
                return false;
        }
        return true;
    }
};

// @lc code=end


int main(){

    return 0;
}