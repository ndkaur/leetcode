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


// time-> O((V+E) + (V+E) + Q)
//  (build adj,parent dsu) + (dfs for each component) + (each query served in O(1))
// space->O(V+E) -> adjlist + dsu+ query 
class Solution { 
    public:
        vector<int> parent;
        vector<int> rank;
    
        int find_parent(int x){
            if(parent[x]==-1)
                return x;
            return parent[x] = find_parent(parent[x]);
        }
    
        void finding_val(int& bitwise_and, int curr, vector<int>& visited, vector<vector<pair<int,int>>>& adj){
            visited[curr] =1;
            for(auto& [itr,wt]:adj[curr]){
                bitwise_and &= wt;
                if(!visited[itr]){
                    finding_val(bitwise_and, itr, visited, adj);
                }
            }
        } 
        
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            // dsu 
            parent.resize(n);
            for(int i=0; i<n; i++){
                parent[i]=-1;
            }
    
            vector<vector<pair<int,int>>> adj(n);
    
            // make uionn groups for the componets that share same parent
            // time= O(V+E)
            for(auto edge:edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
    
                int x = find_parent(u);
                int y = find_parent(v);
    
                if(x!=y)
                    parent[x]=y;
            }
    
            // finding the cost for each node and storing it in an array/map 
            // where the cost for the parent is stored will be the same for all its children
            //O(V+E) ~ dfs for each node
            unordered_map<int,int> mp;
            vector<int>visited(n,0);
    
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    // check if its a alone node or have adjacent nodes
                    int bitwise_and = adj[i].size()==0 ? 0 : adj[i][0].second;  // wt values
                    finding_val(bitwise_and, i, visited, adj);
                    // storing that val for its parent
                    int par= find_parent(i);
                    mp[par]=bitwise_and;
                }
            }
    
            // caluclate for each query
            // time-> O(1)
            vector<int> ans;
            for(auto q:query){ 
                int x = find_parent(q[0]);
                int y = find_parent(q[1]);
                if(x==y){ // belong to same parent return and_val of the parent 
                    ans.push_back(mp[x]);
                }
                else
                    ans.push_back(-1);
            }
            return ans;
        }
    };

    

int main(){

    return 0;
}