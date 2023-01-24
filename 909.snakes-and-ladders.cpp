/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
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

// tc == sc  ->O(N^2)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flat(n*n);
        int idx =0;
        bool leftToRight = true;
        // row with number 1 is the last row so reverse loop
        for(int i=n-1; i>=0; i--){
            if(leftToRight){
                for(int j=0; j<n; j++){
                    flat[idx] = board[i][j];
                    idx++;
                }
            }
            else{
                for(int j=n-1; j>=0; j--){
                    flat[idx] = board[i][j];
                    idx++;
                }
            }
            leftToRight = !leftToRight; // direction change
        }

        vector<int> dist(n*n , -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            // reached destination
            if(curr == n*n -1){
                return dist[curr];
            }
            // moves in dice 1 to 6
            for(int i=1; i<=6; i++){
                int next = curr + i;
                if(next >= n*n) // out of range 
                    continue;
                if(flat[next] != -1){ // if some values is present ie a snake or ledder 
                    next = flat[next] - 1; // new value but 0 base indexing
                }
                if(dist[next] == -1){ // new place we have reached 
                    dist[next] = dist[curr] + 1; // add one to the new number of steps 
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
// @lc code=end


int main(){

    return 0;
}