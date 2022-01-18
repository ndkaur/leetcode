/*
 * @lc app=leetcode id=1786 lang=cpp
 *
 * [1786] Number of Restricted Paths From First to Last Node
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
// fill the dist array and find the dist of the node from the final node 
class Solution {
    int mod = 1e9 + 7;
public:
    int restrictedPaths(vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& dp, int node, const int& n) {
        if(node == n) return 1;
        if(dp[node] != -1) return dp[node];
        int paths = 0;
        
        for(auto& it : adj[node]) {
            if(dist[it.first] < dist[node]) {
                paths = (paths + restrictedPaths(adj, dist, dp, it.first, n)) % mod;
            }
        }
        return dp[node] = paths;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        int source = n, destination = 1;
        dist[source] = 0;
        pq.push({0, source});

        while(pq.size()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto& it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                }
            }
        }
        
        vector<int> dp(n+1, -1);
        return restrictedPaths(adj, dist, dp, destination, n);
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n=5;
    vector<vector<int>> edges={{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
    int ans = sol.countRestrictedPaths(n,edges);
    cout<<ans;
    return 0;
}