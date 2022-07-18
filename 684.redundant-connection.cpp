/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
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
class Solution {
public:
    bool hasCycle(int node, int parent, vector<bool> visited, vector<vector<int>>& graph){
        visited[node]=1;
        for(auto it:graph[node]){
            if(visited[it] && it!=parent) 
                return true;
            else if(!visited[it] && hasCycle(it, node, visited, graph)== true){
                    return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        int a,b;
        vector<vector<int>> graph(n+1);
        vector<bool> visited(n+1,0);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v= edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(hasCycle(u,-1,visited,graph)){
                a=u;
                b=v;
                graph[u].pop_back();
                graph[v].pop_back();
            }
        }
        return {a,b};
    }
};

// Wa are adding one edge to the graph one by one checking if it is forming a cycle. 
// If we see that it is forming a cycle we store the edge and remove that edge from the graph. 
// We return the last edge that we find forming a cycle.

// @lc code=end

//  union find 

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int node){
        if(parent[node]== node)
            return node;
        return parent[node]= findParent(parent[node]);
    }
    bool unionFind(int a, int b){
        a= findParent(a);
        b= findParent(b);
        if(a!=b){
            if(rank[a]>rank[b]){
                rank[a]++;
                parent[b]= a;
            }else{
                rank[b]++;
                parent[a]=b;
            }
            return true;
        }
        return false;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        // make  set fun 
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            //  when both the nodes share a common parent that means a cycyle exist
            if(!unionFind(edges[i][0], edges[i][1])){
                ans= edges[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> ans = sol.findRedundantConnection(edges);
    print(ans);
   return 0;
}