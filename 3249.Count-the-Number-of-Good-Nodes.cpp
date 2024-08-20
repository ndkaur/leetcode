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


class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, int& cnt){
        int total = 0;
        bool isGood = true;
        int subTreeSize = -1; // the size we will compare with others subtree
        // if any child subtree doenot match this value then false 

        for(auto itr:adj[node]){
            if(itr==parent)
                continue;
            int curSize = dfs(itr, node, adj, cnt);
            if(subTreeSize==-1) // the size not given 
                subTreeSize = curSize;
            else if(curSize != subTreeSize){
                isGood = false;
            }
            total += curSize;
        }
        if(isGood)
            cnt++;
        return total+1; // including the parent also
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1; // nodes start from 0
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        // dfs must also calculate cnt of good nodes 
        // and also return the total no of nodes as children that the curr node has
        dfs(0, -1, adj, cnt);
        return cnt;
    }
};


int main(){

    return 0;
}