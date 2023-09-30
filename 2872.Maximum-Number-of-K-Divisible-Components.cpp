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
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        vector<int> sum(n, 0);
        int cnt =0;
        
        
        dfs(0, adj, vis, sum,values,k,cnt); 
        
        return cnt;
    }
    int dfs(int u , vector<vector<int>>& adj, vector<bool> &vis, vector<int>& sum, vector<int>& values,int &k, int& cnt){
        vis[u] =true;
        sum[u] = values[u];
        for (int v : adj[u]) {
            if (!vis[v]) {
                sum[u] += dfs(v, adj, vis, sum, values,k,cnt);
            }
        }
        // sum after visiting all the adjacents of the source node check if divisible by k
        if (sum[u] % k == 0) {
            cnt++;
            return 0; 
        }
            
        return sum[u];
    }
};

int main(){

    return 0;
}