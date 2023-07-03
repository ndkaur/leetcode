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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        set<int> s;
        for(auto r:restricted){
            s.insert(r);
        }

        if(s.size()==0)
            return 0;
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        int cnt=0;
        while(q.size()){
            int node= q.front();
            q.pop();
            cnt++;

            for(auto itr:adj[node]){
                if(vis[itr]==0 && s.count(itr)==0){
                    q.push(itr);
                    vis[itr]=1;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v =  edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        for(auto res:restricted){
            visited[res]=1;
        }
        return 1+dfs(0,adj, visited);
    }
    int dfs(int node , vector<vector<int>>& adj, vector<int>& visited){
        int n = visited.size();
        if(visited[node])  
            return 0;
        visited[node] =1;
        int cnt =0;
        for(auto itr:adj[node]){
            if(!visited[itr]){
                cnt += 1+dfs(itr,adj, visited);
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        for(auto r:restricted)
            vis[r]=1;
        return dfs(0,vis,adj);
    }
    int dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        if(vis[node])
            return 0;
        vis[node]=1;
        int cnt=0;
        for(auto itr:adj[node]){
            if(!vis[itr])
                cnt+= dfs(itr,vis,adj);
        }
        return cnt+1;
    }
};


int main(){

    return 0;
}