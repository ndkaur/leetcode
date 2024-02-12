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

class Solution {
public:
    void dfs(int curr_node, int curr_sum, int cur_time, int& ans, vector<vector<pair<int,int>>>& adj,vector<int>& values,vector<int>& visited,int& maxTime){
        if(cur_time > maxTime)
            return;
        
        if(visited[curr_node]==0) 
            curr_sum += values[curr_node];
        
        visited[curr_node]++; // marking as visited 

        if(curr_node==0) // path = 0->......->0
            ans = max(ans, curr_sum);
        
        for(auto itr:adj[curr_node]){
            int v = itr.first;
            int newTime = itr.second + cur_time;
            dfs(v, curr_sum, newTime, ans, adj, values, visited, maxTime);
        }
        // when coming back and revisiting the same adj itr
        // backtracking
        visited[curr_node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int ans = values[0]; // 0 is always added

        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
         // we can visit any node many times but only add its values ones 
        //  so only when for the first time the node was visited then  we will add its value 
        vector<int> visited(n,0);
        // we need to keep on adding sum of the nodes we visited 
        // we also need to keep a check on if time exceeded maxTime
        // and also track of curr node to start next dfs 

        // curr_node, curr_score, cur_time , ans, adj, values, vis, maxTime
        dfs(0,0,0, ans, adj, values, visited, maxTime);
        return ans;
    }
};  


int main(){

    return 0;
}