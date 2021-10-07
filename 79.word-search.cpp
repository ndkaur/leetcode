/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
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

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
    bool search(vector<vector<char>> &board,int i,int j,string &word,int index){
        if(index==word.length()-1)
            return true;
        board[i][j]=board[i][j]-65;
        if(i>0 && board[i-1][j]==word[index+1] && search(board,i-1,j,word,index+1))
            return true; //up
        if(i<board.size()-1 && board[i+1][j]==word[index+1] && search(board,i+1,j,word,index+1))
            return true;//down
        if(j>0 && board[i][j-1]==word[index+1] && search(board,i,j-1,word,index+1))
            return true;//up
        if(j<board[0].size()-1 && board[i][j+1]==word[index+1] && search(board,i,j+1,word,index+1))
            return true; //down
        
        board[i][j]=board[i][j]+65;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0] && search(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && find(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool find(vector<vector<char>>& board,string &word, int i,int j, int idx){
        int n= board.size();
        int m = board[0].size();
        int w= word.size();
        if(idx==w-1) return true;
        board[i][j]= board[i][j]-65;
        if(i>0 && board[i-1][j]==word[idx+1] && find(board, word, i-1,j,idx+1))
            return true;
        if(j<m-1 && board[i][j+1]==word[idx+1] && find(board, word, i, j+1,idx+1))
            return true;
        if(i<n-1 && board[i+1][j]== word[idx+1] && find(board, word, i+1 , j, idx+1))
            return true;
        if(j>0 && board[i][j-1]== word[idx+1] && find(board, word, i, j-1,idx+1))
            return true;
        board[i][j]= board[i][j]+65;
        return false;
    }
};
// @lc code=end+

int main(){
    Solution sol;
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word ="ABCB";
    bool out=sol.exist(board,word);
    cout<<out;
    return 0;
}