/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 0 = red, 1 = blue
        vector<vector<pair<int,int>>> adj(n);
        for(auto red:redEdges){
            adj[red[0]].push_back({red[1],0});
        }
        for(auto blue:blueEdges){
            adj[blue[0]].push_back({blue[1],1});
        }

        vector<int> dist(n,-1);

        queue<vector<int>> q;
        q.push({0,0,-1});  // node, dist, color

        while(q.size()){
            auto front = q.front();
            q.pop();
            
            auto node = front[0];
            auto distance = front[1];
            auto color = front[2];
              
            // already visited then same dist otherwise curr dist 
            dist[node]  = dist[node]!=-1 ? dist[node] : distance;

            for(auto& itr:adj[node]){
                // node -> {itr node, itr color}
                // already visited and same color as parent of the adj itr
                if(color!=itr.second  && itr.first!=-1){
                    q.push({itr.first, distance+1, itr.second});
                    itr.first = -1; // marking as visited 
                }
            }
        }
        return dist;
    }
};



class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int,int>>> adj(n);
        // red =1, blue =2
        for(auto edge:red){
            adj[edge[0]].push_back({edge[1],1});
        }
        for(auto edge:blue){
            adj[edge[0]].push_back({edge[1],2});
        }
        
        vector<int> dist(n,-1);
        dist[0]= 0;
        // visited[node][color]=  false
        vector<vector<bool>> visited(n, vector<bool>(3,false));
        // the 0 has two colors 1 and 2  
        visited[0][1] = visited[0][2] = true; 

        queue<vector<int>> q;
        q.push({0,0,0}); // node, dist, color
        
        while(q.size()){
            int prevNode = q.front()[0];
            int prevDistance = q.front()[1];
            int prevColor = q.front()[2];
            q.pop();

            for(auto itr:adj[prevNode]){
                int nextNode = itr.first;
                int nextColor = itr.second;
                
                if(nextColor==prevColor)
                    continue;

                if(!visited[nextNode][nextColor]){
                    visited[nextNode][nextColor] = true;
                    if(dist[nextNode]==-1){
                        dist[nextNode] =  1+ prevDistance;
                    }
                    q.push({nextNode, 1+prevDistance, nextColor});
                }
            }
        }
        return dist;
    }
};




class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto r:redEdges){ 
            adj[r[0]].push_back({r[1],1});
        }
        for(auto b:blueEdges){ 
            adj[b[0]].push_back({b[1],0});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{-1,0}}); // node , clor, dist
        vector<int> ans(n,INT_MAX);
        ans[0]=0;
        map<pair<int,int>,int> visited;
        while(!q.empty()){
            int prevNode= q.front().first;
            int prevCol=q.front().second.first;
            int prevDist= q.front().second.second;
            q.pop();
            visited[{prevNode,prevCol}]=1;
            for(auto it:adj[prevNode]){ // node,col
                int nextNode= it.first;
                int nextCol= it.second;
                if(visited[{nextNode,nextCol}]!=1 && (nextCol==1-prevCol || prevCol==-1)){ // not vis and diff color or no color
                    ans[nextNode] = min( 1+prevDist,ans[nextNode]);
                    q.push({nextNode,{nextCol,1+prevDist}});
                }
            }
        }
        for(auto &a:ans){
            if(a==INT_MAX)
                a= -1;
        }
        return ans;
    }
};

// @lc code=end

int main(){
    Solution sol;
    int n=3;
    vvi red={{0,1},{1,2}};
    vvi blue={};
    vector<int> ans = sol.shortestAlternatingPaths(n,red,blue);
    print(ans);
   return 0;
}