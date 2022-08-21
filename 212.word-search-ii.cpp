/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
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
    class Node{
        public:
        Node* links[26]={NULL};
        string flag;
        void put(char ch,Node* node){
            links[ch-'a']=node;
        }
        Node* next(char ch){
            return links[ch-'a'];
        }
        void set(string w){
            flag=w;
        }
        int isEnd(){
            return flag.length();
        }
    };
    // all 4 coordinates (1,0) (-1,0) (0,-1) (0,1)
    int dr[4] = {1, -1, 0, 0}; 
    int dc[4] = {0, 0, -1, 1}; 
    int n,m;
    void dfs(int r, int c, vector<vector<char>>& grid, Node *trie, vector<string>&ans) {
        // out of bound conditions 
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c]=='0' || trie->next(grid[r][c])==nullptr) return;

        char ch=grid[r][c];
        trie=trie->next(ch);
        // reached the end of word trie 
        if(trie->isEnd()){
            ans.push_back(trie->flag);
            // make the trie again empty for other word use 
            trie->flag=""; 
        }
        // mark it as visited 
        grid[r][c] = '0';
        // explore all the directions is not reached the end 
        for (int i = 0; i < 4; i++) { 
            dfs(r + dr[i], c + dc[i],grid,trie,ans);
        }
        grid[r][c]=ch; // backtrack if not matched found 
    }
    
    void insert(string s,Node *root){
        Node *node=root;
        // adding all the words in from of trie /->o->a->t->h   ,  /->p->a
        for(int i=0;i<s.length();i++){
            // does not contains key then add the key  
            if(node->links[s[i]-'a']==nullptr){
                node->put(s[i],new Node);
            }
            // key alredy present move ahead return its trie 
            node=node->next(s[i]);
        }
        // word inserted 
        node->set(s);
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        // add all the words in from of trie to save them for exploring 
        Node *trie=new Node();
        for(auto w:words){
            insert(w,trie);
        }

        vector<string>ans;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                    dfs(j,k,board,trie,ans);
                }
            }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}