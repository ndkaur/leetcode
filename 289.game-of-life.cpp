/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
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
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dirs ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               int live =0;

                for(auto dir:dirs){
                    int nrow = i+dir[0];
                    int ncol = j+dir[1];
                    // checking if valid and counting the live cells 
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && (board[nrow][ncol]==1 || board[nrow][ncol]==-1) ){
                        live++;
                    }
                }
                // if cell is alive live<2 under population ,live>3 over population
                if(board[i][j] ==1 && (live<2 || live>3)){ 
                    board[i][j] = -1; // it will die condition 1 and 3
                }
                // if cell is dead and has 3 live neighbours 
                else if( board[i][j]==0 && live == 3){
                    board[i][j] = 2; // get alive 
                }
            }
        }
        // updating 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j]== 2)
                    board[i][j] = 1;
            }
        }
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dirs ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

        vector<vector<int>> newBoard = board;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               int live =0;

                for(auto dir:dirs){
                    int nrow = i+dir[0];
                    int ncol = j+dir[1];
                    // checking if valid and counting the live cells 
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && (board[nrow][ncol]==1 || board[nrow][ncol]==-1) ){
                        live++;
                    }
                }
                // if cell is alive live<2 under population ,live>3 over population
                if(board[i][j] ==1 && (live<2 || live>3)){ 
                    newBoard[i][j] = -1; // it will die condition 1 and 3
                }
                // if cell is dead and has 3 live neighbours 
                else if( board[i][j]==0 && live == 3){
                    newBoard[i][j] = 2; // get alive 
                }
            }
        }
        // updating 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(newBoard[i][j] == -1)
                    board[i][j] = 0;
                else if(newBoard[i][j]== 2)
                    board[i][j] = 1;
            }
        }
    }
};


class Solution {
public:
    int check(vector<vector<int>>& curr, int i, int j, int m ,int n){
        int live=0;
        if(i>0){
            if(curr[i-1][j]==1) live++;
        }
        if(i<m-1){
            if(curr[i+1][j]==1) live++;
        }
        if(j>0){
            if(curr[i][j-1]==1) live++;
        }
        if(j<n-1){
            if(curr[i][j+1]==1) live++;
        }
        if(i>0 && j>0){
            if(curr[i-1][j-1]==1)live++;
        }
        if(i>0 && j<n-1){
            if(curr[i-1][j+1]==1) live++;
        }
        if(i<m-1 && j>0){
            if(curr[i+1][j-1]==1) live++;
        } 
        if(i<m-1 &&j<n-1){
            if(curr[i+1][j+1]==1) live++;
        }
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> curr=board;
        int m= board.size();
        int n= board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int chk= check(curr, i, j, m,n);
                if(board[i][j]==0){ // already dead
                    if(chk==3) board[i][j]=1;
                }
                else if(board[i][j]==1){ // alive cheack if will stay alive
                    if(chk<2 || chk>3) board[i][j]=0;
                }
            }
        }
    }
};
// @lc code=end



int main(){

    return 0;
}