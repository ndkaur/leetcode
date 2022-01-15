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