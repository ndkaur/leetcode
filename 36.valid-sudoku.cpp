/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
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
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int col[9][9]={0};
        int box[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num= board[i][j]-'0'-1;
                    // for numbering the box 
                    int k = i/3 *3 + j/3;
                    if(row[i][num] || col[j][num] || box[k][num])  // if num is repeated somewhere
                        return false;
                    row[i][num]=col[j][num]=box[k][num]=true; // no repetance of num
                }
            }
        }
        return true;
    }
};


// O(n^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9);
        vector<set<int>> cols(9);
        vector<set<int>> blocks(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int curr= board[i][j];
                // already exist in row col or block
                if(rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3*3) + j/3].count(curr))
                    return false;
                // not exist insert it 
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3*3)+j/3].insert(curr);
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        unordered_set<char> rowSet[N];
        unordered_set<char> colSet[N];
        unordered_set<char> squareSet[N];
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                int sPos = (r / 3) * 3 + c / 3;
                if (rowSet[r].count(val) || colSet[c].count(val) || squareSet[sPos].count(val))
                    return false;
                rowSet[r].insert(val);
                colSet[c].insert(val);
                squareSet[sPos].insert(val);
            }
        }
        return true;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<vector<char>> board = {  {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
    

    bool ans = sol.isValidSudoku(board);
    cout<<ans;
    return 0;
}