/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
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

// @lc code=startc

// dfs
class Solution0{
public:
    void dfs(int node,vector<bool>&visited, vector<vector<int>>& adj){
        visited[node]=true;
        for(auto itr:adj[node]){
            if(visited[itr]==false)
                dfs(itr,visited,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        int sz=con.size();
        if(sz<n-1) return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<sz;i++){
            int u= con[i][0];
            int v= con[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(adj.size(),false);
        int count=0;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count-1;
    }   
};

// increase cnt everytime till i<adj.size()

// union find 

class Solution{
public:
    vector<int> parent;
    vector<int> rank;

     int findParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]= findParent(parent[node]); // path compression 
    }

    void unionn(int u,int v){
        int pu= findParent(u);
        int pv= findParent(v);
        if(pu==pv) return ; // already attached
        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pu]>rank[pv])
            parent[pv]=pu;
        else {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        int extraWire=0;
        int group=n;
        parent = vector<int>(n);
        rank= vector<int> (n,1);
        for(int i=0;i<n;i++){
            parent[i]=i; 
        }
        for(auto c:con){
            int a= c[0];
            int b =c[1];
            // if both parents same then we need extra wire to join them 
            if(findParent(a)==findParent(b))
                extraWire++;
            else{ // parents not same then unite them to some parent and groups will reduce 
                unionn(a,b);
                group--;
            }
        }
        //  if we have more extra wires then groups then only we can make connections 
        if(extraWire >= (group-1))
            return (group-1);
        else 
            return -1;
    } 
};

// @lc code=end


int main(){
    Solution sol;
    int n=4;
    vector<vector<int>> con={{0,1},{0,2},{1,2}};
    int ans =sol.makeConnected(n,con);
    cout<<ans;
   return 0;
}