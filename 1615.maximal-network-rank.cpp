/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
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
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int sz= roads.size();
        vector<int> degree(n,0);
        vector<vector<int>> adj(n,vector<int>(n,false));
        for(int i=0;i<sz;i++){
            int u= roads[i][0];
            int v= roads[i][1];
            adj[u][v]=1;
            adj[v][u]=1;
            degree[u]++;
            degree[v]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, degree[i]+degree[j]- (adj[i][j] ? 1:0));
            }
        }
        return ans ;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> roads={{0,1},{0,3},{1,2},{1,3}};
    int n = 4;
    int ans = sol.maximalNetworkRank(n,roads);
    cout<<ans;
   return 0;
}