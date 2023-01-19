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
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        int ans = 1; 
        vector<int> dist(n);
        dfs(0, s, adj, ans, dist);
        return ans;
    }
    void dfs(int curr, string& s, vector<vector<int>>& adj, int& ans, vector<int>& dist){
        dist[curr] = 1;
        for(auto itr:adj[curr]){
            dfs(itr,s,adj,ans, dist);
            if(s[itr] != s[curr]){
                ans = max(ans, dist[curr] + dist[itr]);
                dist[curr] = max(dist[curr], dist[itr]+1);
            }
        }
    }
};


int main(){

    return 0;
}