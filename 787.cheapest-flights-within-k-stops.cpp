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
// k min flight -> so use max heap 

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
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        // pq is of vi form {dist, node, k}
        priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, k+1});

        while(pq.size()){
            auto t= pq.top();
            pq.pop();
            int dist = t[0];
            int node = t[1];
            int stop = t[2];
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