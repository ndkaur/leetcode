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


// by simple observation we can see that the node which is not in cycle is the safe node 
// find cycle in directed graph we can use topo sort but we need to find the nodes which are not in cycle 
// so to get those specific values of nodes not in cycle we will use coloring method 
// unvisited=0
// visited= unsafe = 1
// visited = safe = no cycle = 2

// t->O(n+e)  s->O(n)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // nodes not involved in cycle are safe 
        vector<int> color(n);
        vector<int> ans;
        // color = 2 = not in cycle 
        // color  =1 = involved in cycle
        for(int i=0; i<n; i++){
            // color 2 or no cycle exist in graph 
            if(color[i]==2 || !dfs(i, color, graph))
                ans.push_back(i);
        }
        return ans;
    }
    // return true if cycle exist
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph){
        color[node] =1; // marking as visited
        for(auto itr:graph[node]){
            // if itr not visited and check for cycle  
            if((color[itr]==0 && dfs(itr, color, graph)==true))
                return true;
            // but if itr is already visited that means its alread visited by someone else then also cycle exist 
            if(color[itr]==1)
                return true; 
        }
        // if cycle not found then this will run and mark color as 2
        color[node] = 2;
        return false;
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