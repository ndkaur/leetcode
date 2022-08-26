/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
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
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m= board[0].size();
        if(n==0) return;

        // if the O is present at first and last colm 
        for(int i=0; i<n; i++){ //
            if(board[i][0] == 'O') // first col
                dfs(i,0, board);
            if(board[i][m-1]) // last col
                dfs(i, m-1, board);
        }

        // if the O  is present at the first and last row
        for(int j=0; j<m; j++){
            if(board[0][j] =='O') // first row
                dfs(0, j, board);
            if(board[n-1][j]) // last row
                dfs(n-1, j, board);
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O')
                    board[i][j] ='X';
                if(board[i][j] == '#')
                    board[i][j] ='O';
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board){
        int n = board.size();
        int m= board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O')
            return;
        board[i][j] ='#';
        dfs(i-1,j, board);
        dfs(i+1,j, board);
        dfs(i, j-1, board);
        dfs(i,j+1, board);
    } 
};

// @lc code=end



int main(){

    return 0;
}