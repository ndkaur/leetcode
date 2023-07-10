/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
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

// we are with with limit k only k stops we can take 
// so if we use pq then its deciding factor will be k stops 
// but if we notice each time the stop value will only increase by 1 
// and so if the increse is by 1 no need to use extra logn for pq 
// we can use simple queue to store the values 


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f:flights){
            int u = f[0];
            int v = f[1];
            int price = f[2];
            adj[u].push_back({v,price});
        }
        // no need to use pq can use simple q
        // q => stops , node, dist
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0;

        while(q.size()){
            auto nde = q.front();
            q.pop();
            int stops = nde.first;
            int node =  nde.second.first;
            int cost = nde.second.second;

            if(stops>k)
                continue;
            for(auto itr:adj[node]){
                int nextNode = itr.first;
                int ncost = itr.second;
                // at most k steps ie stops<=k
                if(cost + ncost < dist[nextNode] && stops<=k){
                    dist[nextNode] =  cost + ncost;
                    q.push({stops+1,{nextNode, dist[nextNode]}});
                }
            }
        }
        if(dist[dst]== 1e9)
            return -1;
        return dist[dst];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>> pq;
        pq.push({0,src}); // dist, node
        k+=1;
        while(!pq.empty() && k--){
            int m= pq.size();
            while(m--){
                int prevDist= pq.front().first;
                int prevNode= pq.front().second;
                pq.pop();
                for(auto &itr:adj[prevNode]){ // node , dist
                    int nextNode= itr.first;
                    int nextDist= itr.second;
                    if(dist[nextNode]> prevDist+nextDist){
                        dist[nextNode]= prevDist+nextDist;
                        pq.push({dist[nextNode],nextNode});
                    }
                }  
            }
        }
        return dist[dst]==INT_MAX ? -1:dist[dst];
    }
};

// O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)
// tle 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        // standard form of dikstra 
        // pq is of vi form {dist, node, k}
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, k+1});

        while(pq.size()){
            auto t= pq.top();
            pq.pop();
            int dist = t[0];
            int node = t[1];
            int stop = t[2];
            // destination node
            if(node== dst)
                return dist;

            if(stop>0){ // k still exist 
                for(auto itr : adj[node]){
                    int nxtnode= itr.first;
                    int nxtdist= itr.second;
                    pq.push({dist+ nxtdist, nxtnode, stop-1});
                }
            }
        }
        return -1;
    }
};



// @lc code=end


int main(){
    Solution sol;
    int n=3;
    vector<vector<int>> flights= {{0,1,100},{1,2,100},{0,2,500}};
    int src= 0;
    int dst=2;
    int k=1;
    int ans = sol.findCheapestPrice(n, flights, src, dst,k);
    cout<<ans;
   return 0;
}