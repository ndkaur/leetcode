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


class Solution0 {
public:

    int dfs(int i, int j, int moves, vector<vector<int>>& fruits, vector<vector<int>>& dp,const vector<pair<int,int>>& dirs){
        int n = fruits.size();

        // reached traget but moves =0
        if(i==n-1 && j==n-1)
            return moves==0? 0: INT_MAX;
        
        // not reached target and moves are exhausted , or its a diagoanl-> all the blocks above diagonal will take more than n-1 steps
        if(moves==0 || i==j)
            return INT_MAX;

        if(dp[i][j]!=-1)
            return dp[i][j];
        
        long long mx = -1;
        for(auto dir:dirs){
            int nrow = i+dir.first;
            int ncol = j+dir.second;
            // valid dir
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){ // boundary check
                int val = dfs(nrow, ncol, moves-1,fruits, dp, dirs);
                if(val!=INT_MAX){
                    mx = max(mx, (long long)val);
                }
            }
        }
        // adding the current cell value 
        return dp[i][j] = (mx<0 ? INT_MAX : fruits[i][j] + mx);
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        // diagonal elemts 
        long long first = 0;
        for(int i=0; i<n; i++){
            first += fruits[i][i];
        }

        // 2nd-> top right, 
        vector<pair<int,int>> top_dirs ={{1,-1},{1,0},{1,1}};
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // row, col, moves
        int second = dfs(0, n-1, n-1, fruits, dp, top_dirs);

        // 3rd = bottom left
        vector<pair<int,int>> bottom_dirs = {{-1,1},{0,1},{1,1}};
        for(auto& row:dp){
            fill(row.begin(), row.end(),-1);
        }
        // row, col, moves
        int third = dfs(n-1, 0, n-1, fruits, dp, bottom_dirs);

        return first +second+third;
    }
};


class Solution {
public:
     int f2(int row, int col, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        // bottom left ptr
        int n = fruits.size();
        if(row<0 || col<0 || row>=n || col>=n)
            return 0;
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int val = fruits[row][col];
        int ans = 0;
        //       Up diag
        //    O  next 
        //       down Diag
        // it cant move about the diag area
        if(row==col){ // on the diag can move only downDiag movement
            ans = max(ans, f2(row+1, col+1, fruits, dp));
        }
        else if(row-1==col){ // one block above the diagonal, 
        // can only move in 2 valid dirs = next, downDiag
            ans = max({ans, f2(row, col+1, fruits, dp), f2(row+1, col+1, fruits, dp)});
        }
        else{ // anywhere belowe the dial all 3 valid moves
            ans = max({ans, f2(row-1, col+1, fruits, dp), f2(row, col+1, fruits, dp), f2(row+1, col+1, fruits, dp)});
        }
        return dp[row][col] = val+ans;
    }
    
    int f1(int row, int col, vector<vector<int>>& fruits, vector<vector<int>>& dp){
        int n = fruits.size();
        //           O
        //  Ldiag   down  Rdiag 
        if(row<0 || col<0 || row>=n || col>=n)
            return 0;

        if(dp[row][col]!=-1)
            return dp[row][col];

        int val = fruits[row][col];
        int ans = 0;

        // can only cover area above diagonal
        if(row==col){ // diagonal , we can only go in Rdiag direction
            ans = max(ans, f1(row+1, col+1, fruits, dp));
        }
        else if(row==col-1){// one block above diag can only move in 2 valid dirs ,  down , Rdiag 
            ans = max({ans, f1(row+1, col+1, fruits, dp), f1(row+1,col, fruits, dp)});
        }
        else{// can go in all 3 dirs = Ldiag, down, Rdiag
            ans = max({ans, f1(row+1, col-1, fruits, dp), f1(row+1, col, fruits, dp), f1(row+1, col+1, fruits, dp)});
        }
        return dp[row][col] = val+ans;
    }
   
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        // diagonal elemts 
        long long first = 0;
        for(int i=0; i<n; i++){
            first += fruits[i][i];
            fruits[i][i] =0;
        }

        // 2nd-> top right, 
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // row, col, moves
        int second = f1(0, n-1, fruits, dp);

        // 3rd = bottom left
    
        int third = f2(n-1, 0, fruits, dp);

        return first +second+third;
    }
};



// // c1, topleft -> can only move diagonal to take n-1 steps 
// // c2-> topright-> can only cover upper half of diagonal as n-1 steps must not exceed
// // c3-> bottom left -> can only cover lower half of the diagonal 



int main(){

    return 0;
}