/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
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

// nodes which are not in cycle 
//  nodes that donot have outgoing edge 

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> degree(n,0);
        for(int i=0;i<n;i++){
            degree[i]= graph[i].size();
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adj[j].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int t= q.front();
            q.pop();
            for(auto itr:adj[t]){
                if(--degree[itr]==0)
                    q.push(itr);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(degree[i]==0)
                ans.push_back(i);
        }
        return ans ;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> graph ={{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    print(ans);
    return 0;
}