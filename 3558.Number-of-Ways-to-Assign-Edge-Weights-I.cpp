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
    const int MOD = 1e9 + 7;
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n + 1);
       
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // finding the max depth 
        vector<int> depth(n+1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;
        int maxDepth = 0;

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto v:graph[u]) {
                if (depth[v]==-1) {
                    depth[v] = depth[u] + 1;
                    maxDepth = max(maxDepth,depth[v]);
                    q.push(v);
                }
            }
        }
        
        vector<vector<int>> dp(maxDepth+1, vector<int>(2, 0));// edged, cost(even,odd)
        dp[0][0]=1;  // Base case: 0 edges, cost is 0 (even)
        // possiblity of making odd at idx [0][0] =1 cause we take 1
        // count how many combinations of 1 and 2 add up to an odd total at every depth 
        //     0  1
        // 0   1  0
        // 1   1  1
        // 2   2  2
        // 3   4  4
        for(int i=1; i<=maxDepth; ++i) {
            // For each edge, try weight 1 or 2
            // even -> 2+2=4,,, 3+5=8
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD; // even = even+even or odd+odd
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; // odd = even+odd or odd+even
        }
    
        return dp[maxDepth][1];
    }
};
// starting node to the max depth node -> how many edges 
// if edges even -> 2edge ->1,2 =3
// odd edged-> 3-> 1,2,1=4.... 2,2,2=6....1,1,1=3


int main(){

    return 0;
}