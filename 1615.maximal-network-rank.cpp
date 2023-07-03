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

//  this code gives wrong ans as we only pick the last two greatest elem anf subtract 1 from them even if the 
// connection between them exist or not .
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> in(n,0);
        for(auto road:roads){
            in[road[0]]++;
            in[road[1]]++;
        }

        int sum=0;
        int sz= in.size();
        for(int i=0;i<sz;i++){
            sum= in[sz-1]+in[sz-2];
        }
        return sum-1;
    }
};


// so  in this code we first check if the connection btw two nodes exist then only subtract 1 else -0
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
        //  nested for loops cause we can get max from any part 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, degree[i]+degree[j]- (adj[i][j] ? 1:0));
            }
        }
        return ans ;
    }
};

//  // now add the two nodes together only if they are adjacent to each other
//         // i=0, j=1 => indeg[0]+indeg[1] if they are adj -1 or -0
//         // i =0  j=2 => if adjacent
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int temp = indeg[i]+indeg[j];
//                 if(adj[i][j])
//                     temp = temp-1;
//                 ans = max(ans, temp);
//             }
//         }
//         return ans;

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> roads={{0,1},{0,3},{1,2},{1,3}};
    int n = 4;
    int ans = sol.maximalNetworkRank(n,roads);
    cout<<ans;
   return 0;
}