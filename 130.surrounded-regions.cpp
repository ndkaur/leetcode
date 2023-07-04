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

// Time Complexity - O(n * m)
// Space Complexity - O(n * m)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m= board[0].size();
        if(n==0) return;
        // all those  adjacent to boundary values mark them # then convert them back to O  as they cant be marked as X
        // those who are left as O after the dfs calls will be converted into X

        // if the O is present at first and last colm 
        for(int i=0; i<n; i++){ //
            if(board[i][0]) // first col
                dfs(i,0, board);
            if(board[i][m-1]) // last col
                dfs(i, m-1, board);
        }

        // if the O  is present at the first and last row
        for(int j=0; j<m; j++){
            if(board[0][j] ) // first row
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
        // out of boundary test cases 
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O')
            return;
        board[i][j] ='#'; // marking it as visited
        // traversing all 4 dirs 
        dfs(i-1,j, board);
        dfs(i+1,j, board);
        dfs(i, j-1, board);
        dfs(i,j+1, board);
    } 
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        // the O that is on boundary can never be converted to X
        // as they can never be surrounded by X form all sides
        // trick here is mark all boundary O as 1 
        // those O which are left unvisited convert them to X
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                        visited[i][j] =1;
                    }
                }
            }
        }
        while(q.size()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto dir:dirs){
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                        q.push({nrow,ncol});
                        visited[nrow][ncol] =1;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j]= 'X';
                }
            }
        }
    }
};

// @lc code=end



int main(){

    return 0;
}