/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,graph,color))
                    return false;
            }
        }
        return true;
    }
    bool bfs(int src, vector<vector<int>>& graph, vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:graph[node]){
                if(color[i]==-1){
                    color[i]=1-color[node];
                    q.push(i);
                }
                else if (color[i]==color[node])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
    bool ans = sol.isBipartite(graph);
    cout<<ans;
   return 0;
}