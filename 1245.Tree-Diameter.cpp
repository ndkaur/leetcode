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
    int dfs(int node, vector<bool>& visited, vector<vector<int>>& adj, int& diameter){
        visited[node] = true;
        auto mx = 0;
        for(auto itr:adj[node]){
            if(!visited[itr]){
                auto depth =  dfs(itr, visited, adj, diameter);
                diameter = max(diameter, depth+mx);
                mx = max(mx, depth);
            }
        }
        return node==0 ? diameter : mx+1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        vector<bool> visited(n+1,0);
        int diameter = 0;
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(0, visited, adj, diameter);
    }
};


class Solution {

public:
int diaa=0;
    int treeDiameter(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size()+1);
       
        
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
         dia(0,graph,-1);
         return diaa;
        


        
    }


    int dia(int start, vector<vector<int>>& graph, int parent){
        int max1=0;
        int max2=0;

        for(int child: graph[start]){
            if(child==parent) continue;
            int dep=dia(child,graph,start);
            if(dep>max1){
                max2=max1;
                max1=dep;
            }
            else if(dep>max2){
                max2=dep;
            }
        }
        int l=max1+max2;
        diaa=max(diaa,l);
        return max1+1;
    }
     
};


int main(){

    return 0;
}