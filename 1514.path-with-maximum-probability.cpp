/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
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
class Solution0 { // time limit exceeded
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& w, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back({v,w[i]});
            adj[v].push_back({u,w[i]});
        }
        priority_queue<pair<double,int> , vector<pair<double,int>> , greater<pair<double,int>>> pq;
        vector<double> dist(n,INT_MIN);
        dist[start]=1.00000;
        pq.push({1.00000, start});
        while(!pq.empty()){
            double we= pq.top().first;
            int prevNode= pq.top().second;
            pq.pop();
            for(auto it:adj[prevNode]){
                int nextNode= it.first;
                double nextW= it.second;
                if(dist[nextNode]<dist[prevNode]*nextW){
                    dist[nextNode] = dist[prevNode]*nextW;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        if(dist[end]==INT_MIN) // does not exist
            return 0.00000;
        return dist[end];
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& w, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back({v,w[i]});
            adj[v].push_back({u,w[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0);
        dist[start]=1;
        pq.push({1.0, start});
        while(!pq.empty()){
            double we= pq.top().first;
            int prevNode= pq.top().second;
            pq.pop();
            for(auto it:adj[prevNode]){
                int nextNode= it.first;
                double nextW= it.second;
                if(dist[nextNode] < we * nextW){
                    dist[nextNode] = we * nextW;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        return dist[end];
    }
};

// @lc code=end


int main(){
    Solution sol;
    int n= 3;
    vector<vector<int>> edges={{0,1},{1,2},{0,2}};
    vector<double> w={0.5,0.5,0.2};
    int start=0;
    int end=2;
    double ans = sol.maxProbability(n,edges,w,start,end);
    cout<<ans;
   return 0;
}