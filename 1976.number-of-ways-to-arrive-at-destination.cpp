/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
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

// cant use straight forward dijkstra like 
// fing the disst from src to dest and then cnt the values that have min val 
//  this is wrong apporcag cause we might reach the same state at the end
// but it may be possible that we have taken different routes to reacht one point inbetween and then 
// that same path leads to the final destination 
// we need to store the number of ways to reach to each current node so to find the total ways to reach destination



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9+7;
        vector<vector<pair<long ,long>>> adj(n);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<long long> ways(n,0); // dp 
        ways[0]=1;
        vector<long long> dist(n,1e12);
        dist[0]=0;
        priority_queue<pair<long long, long long>, vector<pair<long long , long long>> , greater<pair<long long , long long>>> pq;
        pq.push({0,0}); // dist, node
        while(!pq.empty()){
            long long prevDist= pq.top().first;
            long long prevNode= pq.top().second;
            pq.pop();
            for(auto itr:adj[prevNode]){ // node, dist
                long nextNode = itr.first;
                long nextDist= itr.second;

                if(prevDist+ nextDist< dist[nextNode]){
                    dist[nextNode]= prevDist+nextDist;
                    pq.push({dist[nextNode],nextNode});
                    ways[nextNode] = ways[prevNode];
                }else if(nextDist+prevDist == dist[nextNode]){
                    ways[nextNode] = (ways[prevNode]+ways[nextNode])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n= 2;
    vector<vector<int>> roads={{1,0,10}};
    int ans = sol.countPaths(n,roads);
    cout<<ans;
   return 0;
}