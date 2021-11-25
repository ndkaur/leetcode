/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
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
class Solution0 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        // int n = edges.size();
        vector<vector<int>> adjList(n);
        queue<int> q;
        vector<bool> visited(n, false);
        for(int i=0; i< edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int curnode= q.front(); 
            q.pop();
            for(int i=0; i<adjList[curnode].size();i++){
                int sndnode= adjList[curnode][i];
                if(!visited[sndnode]){
                    q.push(sndnode);
                    visited[sndnode]=true;
                }
            }
        }
        if(visited[end])
            return true;
        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        for(int i=0; i< edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return dfs(start,end,adjList,visited);  
    }
    bool dfs(int start,int end, vector<vector<int>>& adjList,vector<bool>& visited){
        if(start==end) return true;
        visited[start]=true;
        for(int it:adjList[start]){
            if(!visited[it]){
                bool res= dfs(it,end,adjList,visited);
                if(res==true)
                    return true;
            }
        }
        return false;
    }
};

// @lc code=end

int main(){
    Solution sol;
    int m=3;
    vector<vector<int>> edges={{0,1},{1,2},{2,0}};
    int start=0;
    int end=2;
    bool ans = sol.validPath(m,edges,start,end);
    cout<<ans;
    return 0;
}