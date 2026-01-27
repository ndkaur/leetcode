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
    void bfs(int root, vector<long long>& dist, vector<vector<int>>& adj, int n){
        queue<int> q;
        q.push(root);
        dist[root] = 0;

        while(q.size()){
            auto node = q.front();
            q.pop();
    
            for(auto itr:adj[node]){
                if(dist[itr]==-1){
                    dist[itr] = dist[node]+1;
                    q.push(itr); 
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int sz = edges.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<long long> distx(n,-1);
        vector<long long> disty(n,-1);
        vector<long long> distz(n,-1);
        bfs(x, distx, adj, n);
        bfs(y, disty, adj, n);
        bfs(z, distz, adj, n);

        int cnt = 0;

        // each node-> dist to x, y, z-> sort , pythogroas
        for(int i=0; i<n; i++){
            long long x_dist = distx[i];
            long long y_dist = disty[i];
            long long z_dist = distz[i];
            // vector<long long> arr = {x_dist, y_dist, z_dist};

            // sort(arr.begin(), arr.end());
            long long mx = max({x_dist, y_dist, z_dist});
            if((x_dist*x_dist)+ (y_dist*y_dist) + (z_dist*z_dist) == 2*mx*mx)
                cnt++;
            // if((arr[0]*arr[0])+ (arr[1]*arr[1])== (arr[2]*arr[2])){
            //     cnt++;
            // }
        }
        return cnt;
    }
};


int main(){

    return 0;
}