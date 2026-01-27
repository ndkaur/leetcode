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


class Solution { // dijkstra also  tc->O((m+n)log m) m = edges.size()
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;

        while(pq.size()){
            int prev_dist = pq.top().first;
            int prev_node = pq.top().second;
            pq.pop();
            if(prev_node==n-1){
                return prev_dist;
            }
            if(prev_dist!=dist[prev_node])
                continue;

            for(auto itr:adj[prev_node]){
                int next_node = itr.first;
                int next_dist = itr.second;
                
                if(dist[next_node]>prev_dist+next_dist){
                    dist[next_node] = prev_dist + next_dist;
                    pq.push({dist[next_node], next_node});
                }
            }
        }
        return -1;
    }
};



int main(){

    return 0;
}