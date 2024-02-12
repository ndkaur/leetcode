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

// find the bridge using tarjan algo 
class Solution {
public:
    void dfs(int node, int parent, int& time, vector<int>& visited, vector<int>& discovery_time, vector<int>& low_time,  vector<vector<int>>& adj,vector<vector<int>>& ans){
        visited[node] = 1;
        discovery_time[node] = low_time[node] = time;
        time++;

        for(auto itr:adj[node]){
            // node->itr 
            if(itr==parent)
                continue;
            if(!visited[itr]){ // visiting it for the first time 
                dfs(itr, node, time, visited, discovery_time, low_time,adj, ans);
                // there is a possiblity that the node has some adjacents itr whose  iteration is completed 
                // or maybe its low time is changed , so check if curr nodes low time also gets changed or not 
                low_time[node] = min(low_time[node], low_time[itr]);
                // now check if this nedge is a bridge 
                // so the edge will be a bridge if its not in a cylce 
                // any node that is in a cycle its low values must have been changed somewhere 
                // so a node whose low time > then the discovery time of other node 
                // itr not in cycle and only visited ones so itr low time didnt changed anywhere 
                if(low_time[itr] > discovery_time[node]){
                    ans.push_back({node, itr});
                }
            }
            else{ // already visited, now getting visited by some other differnt path , can occur in cycle
                // if again getting visited then change its low time 
                low_time[node] = min(low_time[node], discovery_time[itr]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for(auto c:con){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> ans;
        int time = 0;
        vector<int> visited(n,0);
        vector<int> discovery_time(n,-1);
        vector<int> low_time(n,-1);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                // node, parent, time
                dfs(i, -1, time, visited, discovery_time, low_time, adj, ans);
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}