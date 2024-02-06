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


class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int dijkstra(int source, int dest){
        int n = adj.size();
        vector<int> dist(n,INT_MAX);
        dist[source] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,source});

        while(pq.size()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node==dest)
                return wt;

            for(auto itr:adj[node]){
                int newNode = itr.first;
                int newWt = itr.second;

                if(wt+newWt < dist[newNode]){
                    dist[newNode] = wt+newWt;
                    pq.push({wt+newWt , newNode});
                }
            }
        }
        return (dist[dest]==INT_MAX) ? -1 : dist[dest];
    }
    Graph(int n, vector<vector<int>>& edges) { // O(N)
        adj.resize(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
        }
    }
    
    void addEdge(vector<int> edge) { // O(1)
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) { // O(N + E * log(E))
        return dijkstra(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


int main(){

    return 0;
}