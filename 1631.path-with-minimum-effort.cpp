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

// time complexity -> e log v
// e = totoal no of edges -> n*m
// tiem complexity = (n*m*4) log (n*m)

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
// @lc code=end


int main(){

    return 0;
}