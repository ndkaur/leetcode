/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
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
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int,int>> dirs ={{0,1},{1,0},{0,-1},{-1,0}};
        
        ocean[i][j] = true;

        for(auto dir:dirs){
            int ni = i + dir.first;
            int nj = j + dir.second;
            if(ni>=0 && ni<n && nj>=0 && nj<m && !ocean[ni][nj] && heights[ni][nj]>=heights[i][j]){
                dfs(ni, nj, heights, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // if we move water inside from grid to ocean -> if next grid smaller or equal
        // move from ocean to grid -> if next grid is greater or equal 
        // the pacific and atlantic will be filled , ie the sides touching ocean 
        // the grid which is visted by both 
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            // j=0 pacific 
            dfs(i, 0, heights, pacific);
            // j= m-1 atlantic
            dfs(i, m-1, heights, atlantic);
        }

        for(int j=0; j<m; j++){
            // i=0 pacifc
            dfs(0, j, heights, pacific);
            // i= n-1 atlantic 
            dfs(n-1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlantic[i][j]==pacific[i][j] && pacific[i][j]==true)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};


// O(M*N)
// O(M*N),

// from one block to ocean can flow if less than or equal to other 
// but if we moving from ocen direction to blocks then it should be greater or equal
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        if(m==0)
            return ans;
        int n= heights[0].size();
        if(n==0)
            return ans;

        // check for both oceans pacific->top , left   atlantic -> right, bottom
        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> atl(m, vector<bool>(n));
        
        // for the first and last col
        for(int i=0; i<m; i++){
            dfs(i,0,heights, pac);// left pac
            dfs(i, n-1, heights, atl); // right atl
        }

        // for the first and last row
        for(int j=0; j<n; j++){
            dfs(0, j, heights, pac); // top ->pac
            dfs(m-1,j, heights, atl) ; // bottom -> atl
        }

        // intersection of both pac and atl is our ans 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        int m = heights.size();
        int n= heights[0].size();

        visited[i][j]= true;
        // up
        if(i-1>=0 && visited[i-1][j]!= true && heights[i-1][j]>= heights[i][j])
            dfs(i-1, j, heights, visited);
        // down 
        if(i+1<m && visited[i+1][j]!= true && heights[i+1][j]>= heights[i][j])
            dfs(i+1, j, heights, visited);
        //left
        if(j-1>=0 && visited[i][j-1]!= true && heights[i][j-1]>= heights[i][j])
            dfs(i, j-1, heights, visited);
        // right 
        if(j+1<n && visited[i][j+1]!= true && heights[i][j+1]>= heights[i][j])
            dfs(i, j+1, heights, visited);
    }
};
// @lc code=end


int main(){

    return 0;
}