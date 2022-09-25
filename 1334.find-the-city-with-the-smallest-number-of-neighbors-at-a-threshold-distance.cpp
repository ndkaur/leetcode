/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
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
class Solution0 {  // floyd warshall algo 
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e6)); 
        for(auto e:edges){
            int a= e[0];
            int b= e[1];
            int weight= e[2]; 
            adj[a][b]= weight;
            adj[b][a]= weight;
        }
        //self distance 2->2 =0 , 3->3=0
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]= min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        int mxcount=n;
        int mxcity=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold)
                    count++;
            }
            if(mxcount>=count){
                mxcount=count;
                mxcity=i;
            }
        }
        return mxcity;
    }
};

class Solution {  // dijkstar algo 
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> g;
        for(auto& edge:edges){
            g[edge[0]].push_back({edge[1],edge[2]});
            g[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int> count(n+1,0);
        // we want for all i as source
        for(int i=0;i<=n-1;i++){
            priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
            vector<int> distance(n+1,INT_MAX);
            distance[i]=0;
            pq.push({0,i}); // w, node

            while(!pq.empty()){
                int dist = pq.top().first;
                int prevNode= pq.top().second;
                pq.pop();

                for(auto it:g[prevNode]){ // node,w
                    int next= it.first;
                    int nextDist= it.second;

                    if(distance[next]> dist+nextDist){
                        distance[next]= nextDist+dist;
                        pq.push({distance[next],next});
                    }
                }
            }

            for(int j=0;j<=n-1;j++){
                if(distance[j]<= distanceThreshold && distance[j]!=0){
                    count[i]++;
                }
            }
        }

        int mncount=INT_MAX;
        for(int i=0;i<=n-1;i++){
            mncount =min(mncount,count[i]);
        }
        int mxans= INT_MIN;
        for(int i=0;i<=n-1;i++){
            if(count[i]==mncount)
                mxans= max(mxans,i);
        }
        return mxans;
    }
};

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // make adj list
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            vector<int> temp=it;
            int u= temp[0];
            int v= temp[1];
            int wt= temp[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        int res = INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> count = dijkstra(adj,i,n);
            int cnt=0;
            for(auto it:count){
                if(it<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=res){
                res= cnt;
                ans=i;
            }
        }
        return ans;
    }
        
    vector<int> dijkstra(vector<pair<int,int>>adj[], int i, int n){ 
            vector<int> distance(n,1e8);
            distance[i]=0;
            priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
            
            
            pq.push({0,i}); // {wt, node}
            
            // filling the dist array 
            while(!pq.empty()){
                int dist= pq.top().first;
                int pnode= pq.top().second;
                pq.pop();
                
                for(auto it:adj[pnode]){
                    int next= it.first;
                    int ndist= it.second;
                    if( distance[next] > ndist+ dist){
                        distance[next]= distance[pnode]+ ndist;
                        pq.push({distance[next],next});
                    }
                }
            }
            return distance;
    }
};





// @lc code=end


int main(){
    Solution sol;
    int n= 5;
    vector<vector<int>> edge={{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int dist=2;
    int ans = sol.findTheCity(n,edge,dist);
    cout<<ans;
   return 0;
}