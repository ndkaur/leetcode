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
    int dfs(int root, int par, int dist, vector<vector<pair<int,int>>>& adj, int& speed){
        int cnt = (dist%speed) ? 0 : 1;
        for(auto itr:adj[root]){
            int u = itr.first;
            int wt = itr.second;
            if(u!=par){
                cnt += dfs(u, root, dist+wt , adj, speed);
            }
        }
        return cnt;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int  n = edges.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> ans;
        // cnt from each eadge as taking it as signal
        for(int i=0; i<=n; i++){
            int nodeCnt = 0; // store prev cnt of dfs one child 
            int res = 0;
            for(auto itr:adj[i]){
                int node = itr.first;
                int wt = itr.second;
                int t = dfs(node, i, wt, adj, signalSpeed);
                res += nodeCnt * t; // if only one child then 0*cnt = 0
                nodeCnt += t; // leftchild cnt * right child cnt, so store the prev cnt 
            
            ans.push_back(res);
        }
        return ans;
    }
};

int main(){

    return 0;
}