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

// time comp-> dij = (E+V) logV
// dijkstra running E times so total comp =  O(E* (E+V)logV)
// space compl-> O(E+V)

class Solution {
public:
    const int INF=2e9;
    int dijkstra(int n, int src, int dest, vector<vector<pair<int,int>>>& adj){
        vector<int> dist(n,INF);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});

         while(pq.size()){
            int prev_wt =  pq.top().first;
            int prev_node = pq.top().second;
            pq.pop();
            
            if(prev_wt>dist[prev_node]){
                continue;
            }

            for(auto& itr:adj[prev_node]){
                int next_node = itr.first;
                int next_wt = itr.second;

                if(prev_wt + next_wt < dist[next_node]){
                    dist[next_node] = prev_wt + next_wt;
                    pq.push({dist[next_node], next_node});
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int,int>>> adj(n);
        // building adj list excluding -1 weights
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(wt!=-1){
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }

        // now find the dist for the first time and check which condition it satisfys
        int sum = dijkstra(n, source, destination, adj);
        
        // case1-> sum is of all the +ve values not including the -1
        // and the sum of src to destination is +ve and less than target -> means there is no possiblity to change any -1 to 1
        // and get the distance equal to target, sum = 5, 0->2 and target is 6 , no way to get equal as we cant change 5 
        if(sum<target){
            return {}; 
        }
        
        // case2-> when sum==target, and we have few -1 unchange , so now it doent matter
        // what value we give to -1, as the shortest path is alredy found 
        // but acc to que we need to change all -1 to some +ve value, so we can change it to INF
        bool isEqualTarget = (sum==target);

        // changing the -1 weights or
        // case3-> when we need to change -1 to make equal to target
        // we will iterate and find the -1 wt , change it to 1 and apply dijkstra on it
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
        
            if(edge[2]!=-1){ // cant change already +ve value
                continue;
            }

            if(isEqualTarget){
                edge[2]=INF; // case2
            }
            else{
                edge[2] = 1; // case3 , -1 to 1 and then apply dijkstra
            }
            // also change the values in adj list 
            // these edges will be added for the first time as 
            // when we intially made adj list we didnt added -1 wt edges
            adj[u].push_back({v, edge[2]});
            adj[v].push_back({u, edge[2]});

            if(!isEqualTarget){
                int newSum = dijkstra(n, source, destination, adj);
                // we applied dijkstra with newely added edges and if we get a sum from src to dest 
                // then we can change the values to target-sum to make it eactly equal
                if(newSum<=target){
                    isEqualTarget = true;
                    edge[2] += target-newSum; 
                }
            }
        }
        return isEqualTarget ? edges: vector<vector<int>>();
    }
};



int main(){

    return 0;
}
