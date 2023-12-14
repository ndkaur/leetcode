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

// a bomb i lies in proximity of bomb j only when 
// distance btw center <= radius of ith bomb 
// To create graph, simply we need to loop over bombs list, and then for each bomb i, we need to check if a bomb j lies withing its proximity.

typedef long long ll;
class Solution {
public:
    bool check(ll x1, ll y1, ll x2, ll y2, ll d){
        ll x = (x1-x2) * (x1-x2);
        ll y = (y1-y2) * (y1-y2);
        return (x+y <= d*d);
    }
    int dfs(int node, int n, vector<vector<int>>& adj, vector<bool>& visited){
        int cnt = 1;
        visited[node] = true;

        for(auto& itr:adj[node]){
            if(!visited[itr]){
                cnt += dfs(itr, n, adj, visited);
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 0;
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && check(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1],bombs[i][2])){
                    adj[i].push_back(j);
                }
            }
        }
        // dfs
        for(int i=0; i<n; i++){
            vector<bool> visited(n,false);
            //cnt the max nodes that can be visited when starting dfs from each node seperately 
            ans = max(ans, dfs(i, n, adj, visited));
        }
        return ans;
    }
};


int main(){

    return 0;
}