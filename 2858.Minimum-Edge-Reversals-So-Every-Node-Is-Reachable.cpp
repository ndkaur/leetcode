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



class Solution0 { //O(n^2)
public:
    int dfs(int node, int prev, vector<vector<int>>&adj, vector<vector<int>>& radj, map<pair<int,int>, int>& dp){
        int ans = 0;

        if(dp.find({node,prev})!=dp.end()) // already exist
            return dp[{node,prev}]; 

        // direct grph 
        for(auto itr:adj[node]){
            if(itr!=prev){ // not already visited
                ans += dfs(itr, node, adj, radj, dp);
            }
        }

        // reverse graph -> reverse add add one 
        for(auto itr:radj[node]){
            if(itr!=prev){
                ans += 1 + dfs(itr, node, adj, radj, dp);
            }
        }
        // store the result in dp to avoid repetance 
        return dp[{node,prev}]  = ans; 
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);// u->v
        vector<vector<int>> radj(n); // v->u

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        // to store result 
        map<pair<int,int>, int> dp; // {u,v}, totalval
        vector<int> ans;

        for(int i=0; i<n; i++){
            ans.push_back(dfs(i, -1, adj, radj, dp));
        }
        return ans;
    }
};


class Solution { //O(n)
public:
    int dfs(int node, int prev, vector<vector<pair<int,int>>>& adj){
        int cnt = 0;
        for(auto itr:adj[node]){
            int v = itr.first;
            int dir = itr.second;
            if(v!=prev){
                cnt += dir;
                cnt += dfs(v, node, adj);
            }
        }
        return cnt;
    }
    void dfs2(int node, int parent, int direction, vector<vector<pair<int,int>>>& adj, vector<int>& ans){   
        // with the value already calculated for parent to want to find for its adj itr 
        int value = ans[parent];
        // if direction is 0, direct edge from parent to node, but for node its reverse edge so cnt increase  
        //  if direction is 1, reverse edge from parent->node, but it is a direct edge from node->parent so node value must decrease
        
        // parent to node is a direct edge but we are calculating from the prespective of node so for node to parent it will be an reverse edge so increase its count 

        if(direction==1) // curr node has direct edge to parent
            value--;
        else
            value++;
        
        ans[node] = value;

        for(auto itr:adj[node]){
            int v = itr.first;
            int dir = itr.second;
            if(v!=parent){
                dfs2(v, node, dir, adj, ans);
            }
        }

    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v,0}); // direct edge
            adj[v].push_back({u,1}); // reversed edge
        }

        // so step 1:- find the value of reversal cnt for 0
        // step2:- using 0 calculate the answer for remaining nodes 
        vector<int> ans(n,0);
        ans[0] = dfs(0, -1, adj);

        // now we have cnt of 0 then calculate for others
        for(auto itr:adj[0]){
            int v = itr.first;
            int dir = itr.second;
            // v, parent=0, dir
            dfs2(v, 0, dir, adj, ans);
        }
        return ans;
    }
};




int main(){

    return 0;
}