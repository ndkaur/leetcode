/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
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

// find the cycle -> dfs = vis and dfs visi array 
//  topo sort method 

 // o(n+e) // o(n)
// if there is no cycle then only we can traverse each node 
// khans algo -> topo sort order tells if no cycle 
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto p:pre){
            // a->b
            int u= p[0];
            int v= p[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i=0;i<indeg.size(); i++){
            if(indeg[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;
            for(auto itr:adj[node]){
                indeg[itr]--;
                if(indeg[itr]==0){
                    q.push(itr);
                }
            }
        }
        if(cnt==n)// topo sort order found no cycle present so all nodes are covered 
            return true;
        return false;
    }
};


class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> color(num);
        bool has_cycle;
        for(auto p:pre){
            adj[p[0]].push_back(p[1]);
        }
        has_cycle=false;
        for(int i=0;i<num;i++){
            if(color[i]==0)
                dfs(i,adj,color,has_cycle);
            if(has_cycle) return false;
        }
        return !has_cycle;
    }
    void dfs(int x, vector<vector<int>>& adj,vector<int>& color, bool &has_cycle){
        color[x]=1;
        for(auto it:adj[x]){
            if(color[it]==0)
                dfs(it,adj,color, has_cycle);
            else if(color[it]==1)
                has_cycle = true;
        }
        color[x]=2;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int num=2;
    vector<vector<int>> pre={{1,0}};
    bool ans = sol.canFinish(num,pre);
    cout<<ans;
   return 0;
}