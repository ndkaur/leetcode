/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
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


// Time complexity:O(M∗N∗log(M∗N))O(M * N * log(M * N))O(M∗N∗log(M∗N))
// The time complexity for Dijkstra's Algorithm is O(E * log(E)), where E is the number of edges in the graph. 
// In our case, we can consider the number of edges are M * N.

// Space complexity:O(M∗N)O(M * N)O(M∗N)
// Since we are storing the minimum effort for the path from the starting point to each cell, then the space complexity is O(M * N).
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        using pipii = pair<int, pair<int,int>>;
        // weight , i, j
        priority_queue<pipii , vector<pipii> , greater<pipii>> pq;

        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));

        vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();

            int weight = node.first;
            auto cord = node.second;
            int row= cord.first;
            int col = cord.second;
            if(dist[row][col] < weight)
                continue;
            if(row == n-1 && col == m-1)
                return weight;
            for(auto dir : dirs){
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                // valid dirs
                if(nrow<0 || nrow >=n)  
                    continue;
                if(ncol<0 || ncol>=m)
                    continue;

                int nweight =  abs(heights[row][col] - heights[nrow][ncol]);
                nweight = max(nweight , weight);
                if(dist[nrow][ncol] <= nweight)
                    continue;
                dist[nrow][ncol] = nweight;
                pq.push({nweight,{nrow,ncol}});
                
            }
        }
        return 0;
    }
};



// Time complexity:O(M∗N∗log(106))O(M * N * log(10^6))O(M∗N∗log(106))
// The time complexity for Binary Search is log(upper_bound - lower_bound) and in our 
// case the maximum range in 10^6. and since we are doing DFS in each iteration 
// knowing that the time complexity for the single DFS is O(N * M) then the total time complexity is O(M * N * log(10^6)).
// Space complexity:O(M∗N)O(M * N)O(M∗N)
// Since we are storing the visited array for each cell and the DFS recursion stack complexity is also O(M * N), then the space complexity is O(M * N).

// binary search 
class Solution {
public:
    bool bfs(int limitEffortmid , vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size();
        
        queue<pair<int,int>> q;
        q.push({0,0});

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        vector<vector<int>> visited(n, vector<int>(m,0));
        visited[0][0] = 1;

        while(q.size()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // reached destination 
            if(row==n-1 && col==m-1)
                return true;

            for(auto dir:dirs){
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){
                    int neffort = abs(heights[nrow][ncol]-heights[row][col]);
                    
                    if(neffort <= limitEffortmid){
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
       
        int l = 0;
        int r = 1e6;
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(bfs(mid, heights)){
                ans = mid;
                r = mid-1;
            }
            else 
                l = mid+1;
        }
        return ans;
    }
};



// @lc code=end


int main(){

    return 0;
}