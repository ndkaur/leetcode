/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
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

// topo order but for outdegre
// a node is safe if its outdegree =0
// those nodes with outdegree 0 we can visit there adjacent node and make there degree also 0 
class Solution { // t->O(n+e)  s->O(n)
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        // calculate the outdegree of each g in graph
        vector<int> outdegree(n,0);
        for(int i=0;i<n;i++){
            outdegree[i]= graph[i].size();
        }
        // adjacent list based upon indegree 0->1,2  instead as 1->0 , 2->0
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                 adj[j].push_back(i);
            }
        }
        // all those who have outdegree 0 push in queue
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        // working on the filled queue
        while(!q.empty()){
            int t= q.front();
            q.pop();
            for(auto itr:adj[t]){
                outdegree[itr]--;
                if(outdegree[itr]==0)
                    q.push(itr);
            }
        }
        // so in the end we have got the ele with outdegree reduced to 0
        vector<int> ans;
        for(int i=0;i<outdegree.size();i++){
            if(outdegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        // reverse the direction of edges of graph 
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(auto j: graph[i]){
                adj[j].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(q.size()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto itr:adj[node]){
                indeg[itr]--;
                if(indeg[itr]== 0)
                    q.push(itr);
            }
        }
       
        sort(topo.begin(), topo.end());
        return topo;
    }
};

// we made adjacent list in form of adj(val).push_back(idx)
// because there are cases when idx = 5 and val ={}  but it is possible that idx 5 is adjcaent to someone else  eg idx= 3 val={5}


// coloring method 
// unvisited=0
// visited= unsafe =
// visited = safe = no cycle = 2
class Solution { // t->O(n+e)  s->O(n)
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n);
        vector<int> ans;
        // node visited || unvisited+ not contain cycle
        for(int i=0;i<n;i++){
            if(color[i]==2 || !dfs(graph, color, i))
                ans.push_back(i);
        }
        return ans;
    }
    // dfs will check if cycle exist or not 
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node){
        color[node]=1; // mark visited but unsafe
        for(auto cur: graph[node]){
            // (not visited && cycle exist) ||  ( visited but cycle exist so unsafe )
            if((color[cur]==0 && dfs(graph,color, cur)) || color[cur]==1)
                return true;
        }
        // only run if cycle not found
        color[node]=2;
        return false; // if no cycle found 
    }
}; 



// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> graph ={{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    print(ans);
    return 0;
}