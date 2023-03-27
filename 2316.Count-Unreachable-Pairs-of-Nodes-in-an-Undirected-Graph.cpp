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
    long long countPairs(int n, vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u =edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> group;
        long long ans =0;
        for(int i=0; i<n; i++){
            if(visited[i])
                continue;
            
            visited[i]=1;

            int cnt = 1;// cnt of visited nodes after one dfs
            queue<int> q;
            q.push(i);
            while(q.size()){
                auto node = q.front();
                q.pop();
                for(auto itr:adj[node]){
                    if(!visited[itr]){
                        visited[itr]=1;
                        q.push(itr);
                        cnt++;
                    }
                }
            }
            group.push_back(cnt);
        }
        // group will have no of all connected nodes
        // ans = visited nodes in one iteration * non visited node 
        for(int g:group){
            ans += (long long)g*(n-g);
        }
        // nodes are repeated 
        return ans/2;
    }
};


int main(){

    return 0;
}