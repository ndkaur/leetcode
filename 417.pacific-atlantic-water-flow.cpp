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