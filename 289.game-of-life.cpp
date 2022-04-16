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