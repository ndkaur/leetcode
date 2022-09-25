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
// t-> O(n + elogn)
// s->o(n+e)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time:times){
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]= 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            int time  = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto itr:adj[node]){
                int newNode = itr.first;
                int newTime = itr.second;
                if(dist[newNode] > dist[node] + newTime){
                    dist[newNode] = dist[node] + newTime;
                    pq.push({dist[newNode], newNode});
                }
            }
        }
        int ans = 0 ;
        // min time to recive all signals will actually be the max of all 
        for(int i=1; i<dist.size(); i++){
            ans = max(ans, dist[i]);
        }
        return ans == INT_MAX ? -1 :ans;
    }
};


class Solution { 
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time:times){
            int u= time[0];
            int v=time[1];
            int w= time[2];
            adj[u].push_back({v,w});
        }
        vector<int> distance(n+1, INT_MAX);
        queue<int> q;
        q.push(k);
        distance[k]=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto itr:adj[node]){
                int next= itr.first;
                int ndist= itr.second;
                if(distance[next] > distance[node]+ ndist){
                    distance[next] = distance[node]+  ndist;
                    q.push(next);
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX)
                return -1;
            res = max(res, distance[i]);
        }
        return res;
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