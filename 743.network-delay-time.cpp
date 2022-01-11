/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
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
class Solution { // dijkstra
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto t:times){
            int x= t[0], y=t[1], w=t[2];
            adj[x].push_back({y,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0; // src
        pq.push({0,k}); // dist,node

        while(!pq.empty()){
            int prevDist= pq.top().first;
            int prevNode=pq.top().second;
            pq.pop();
            for(auto itr:adj[prevNode]){
                int nextNode= itr.first;
                int nextDist= itr.second;
                if(dist[nextNode]>dist[prevNode]+nextDist){
                    dist[nextNode] = dist[prevNode]+nextDist;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        int ans =INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans, dist[i]); // we need max time 
        }
        return ans == INT_MAX ? -1:ans; // if ans == int max ie infinity
        // menas no path exist 
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n= 4;
    int k =2;
    int ans= sol.networkDelayTime(times,n,k);
    cout<<ans;
    return 0;
}