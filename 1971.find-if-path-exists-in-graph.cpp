/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
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

//  bfs ->tc-> O(n+e)  sc->O(n+e)+O(n)+O(n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,false);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto itr:adj[node]){
               if(!visited[itr]){
                   q.push(itr);
                   visited[itr]=1;
               }
            }
        }
        if(visited[destination])
            return true;
        return false;
    }
};  

//   for(auto itr:adj[start]){
        //     if(!visited[itr]){
        //         if(dfs(itr, end, adj, visited))
        //             return true;
        //     }
        // }


//  dfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        for(int i=0; i< edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return dfs(start,end,adjList,visited);  
    }
    bool dfs(int start,int end, vector<vector<int>>& adjList,vector<bool>& visited){
        if(start==end) return true;
        visited[start]=true;
        for(int it:adjList[start]){
            if(!visited[it]){
                bool res= dfs(it,end,adjList,visited);
                if(res==true)
                    return true;
            }
        }
        return false;
    }
};

// @lc code=end

int main(){
    Solution sol;
    int m=3;
    vector<vector<int>> edges={{0,1},{1,2},{2,0}};
    int start=0;
    int end=2;
    bool ans = sol.validPath(m,edges,start,end);
    cout<<ans;
    return 0;
}