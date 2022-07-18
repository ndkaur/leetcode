/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
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
class Solution0 {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        int sz= c.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<sz;i++){
            int u= c[i][0];
            int v= c[i][1];
            //u->v edge 1
            adj[u].push_back({v,1});
            // v->u edge self created in 0
            adj[v].push_back({u,0});
        }
        int ans =0;
        vector<bool> visited(n,false);
        dfs(0,ans,visited,adj);
        return ans;
    }
    void dfs(int node, int &ans , vector<bool>& visited,vector<pair<int,int>> adj[]){
        visited[node]=true;
        for(auto pir:adj[node]){
            int nf= pir.first;
            int weight= pir.second;
            if(visited[nf]==false){
                ans+=weight;
                dfs(nf,ans, visited, adj);
            }
        }
    }
};

// adj list ->
// 0-> [1,1],[4,0]
// 1-> [0,0],[3,1]
// 2 -> [3,1]
// 3-> [1,0],[2,0]
// 4-> [5,1],[0,1]
// 5-> [4,0]

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<bool> visited(n,false);
        visited[0]=true;
        int inverse=0;
        int i=0;
        while(i<c.size()){
            if(visited[c[i][1]]){
                // if visited value is on right side 
                // [2,0] we want 0 on right side 
                visited[c[i][0]]=true; // mark other value as seen
            }
            else if(visited[c[i][0]]){
                // if visited value is on left side need for path change 
                inverse++;
                visited[c[i][1]]=true;
            }
            else {
                c.push_back(c[i]); // if none of the value is seen then add the whole pair at last of connections 
            }
            i++;
        }
        return inverse;
    }
}; 

// dfs
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        int sz= c.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<sz;i++){
            int u= c[i][0];
            int v= c[i][1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,-1});
        }
        int ans =0;
        vector<bool> visited(n,false);
        dfs(0,ans,visited,adj);
        return ans;
    }
    //  we have to change the u->v edges into v->u so count the u->v edges 
    void dfs(int node, int &ans , vector<bool>& visited,vector<vector<pair<int,int>>> &adj){
        if(visited[node])
            return;
        visited[node]=true;
        for(auto pir:adj[node]){
            int nf= pir.first;
            int weight= pir.second;
            if(visited[nf]==false && weight==1){
                ans++;
            }
            dfs(nf,ans, visited, adj);
        }
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> con ={{0,1},{1,3},{2,3},{4,0},{4,5}};
    int n= 6;
    int ans = sol.minReorder(n,con);
    cout<<ans;
    return 0;
}