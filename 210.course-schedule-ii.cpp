/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
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
// Time Complexity : O( numCourses + prerequesties.size() )
// Space Complexity : O( numCourses )
class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre){
        vector<vector<int>> adj(num);
        vector<int> indegree(num,0);
        vector<int> topo;
        queue<int> q;
        for(auto p:pre){
            int course= p[0]; // u
            int depend= p[1];//v 
            // u->v 
            adj[course].push_back(depend);
            indegree[depend]++; // v++
        }
        // thosw who have 0 indeg
        for(int i=0;i<num;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            count++;
        }
        if(count!=num) return {};
        reverse(topo.begin(),topo.end());
        return topo;
    }
};
// check cyle -> if no cycel then topo exist
// o(n+e)
// o(n+e)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto p: pre){
            // u,v   u->v
            int u= p[0];
            int v= p[1];
            adj[u].push_back(v);
        }
        vector<int> ans;
        vector<int> visited(n,0);
        
        bool flag = true;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                if(!dfs(i, ans, visited, adj)){
                    flag = false; // cycle exist so no topo sort
                    break;
                }
            }
        }
       
        if(!flag)
            return vector<int>();
        return ans;
    }
    
    bool dfs(int node, vector<int>& ans, vector<int>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        for(auto itr:adj[node]){
            if(visited[itr]==1)
                return false;
            if(visited[itr]==0){
                if(!dfs(itr, ans, visited, adj)) // cycle present
                    return false;
            }
        }
        visited[node]= 2;
        ans.push_back(node);
        return true;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int num=2;
    vector<vector<int>> pre={{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = sol.findOrder(num,pre);
    print(ans);
   return 0;
}