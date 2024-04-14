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
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        vector<int> visited(n,0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(pq.size()){
            auto prevDist = pq.top().first;
            auto prevNode = pq.top().second;
            pq.pop();

            // already visited
            if(visited[prevNode]==1)
                continue;

            // already calculated min dist for curr node if it cant reach in time just skip it 
            if(prevDist>=disappear[prevNode])
                continue;

            visited[prevNode] = 1;

            for(auto itr:adj[prevNode]){
                int nextNode = itr.first;
                int nextDist = itr.second;
                // we all togethe keep a check if dist less equal than diapper distance and then only take it , elese dont calculate dist for it 
                if(prevDist + nextDist < dist[nextNode] && prevDist + nextDist <= disappear[nextNode]){
                    dist[nextNode] = prevDist + nextDist;
                    pq.push({dist[nextNode], nextNode});
                } 
            }
        }

        vector<int> ans;
        // we want to simply check the diapper dis is les or equal so take it or -1
        for(int i=0; i<n; i++){
            // we didint checked <= here cause we already checked while doing dijkstra 
            if(dist[i]<disappear[i]){
                ans.push_back(dist[i]);
            }
            else
                ans.push_back(-1);
        }
        return ans;
    }
};


int main(){

    return 0;
}