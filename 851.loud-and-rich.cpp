/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start

//Topological sort 
//  cause here the order of occurence matter 

// dfs
class Solution {
public:
    void dfs(int node, vector<bool>& visited, stack<int>& stk, vector<vector<int>>& adj){
        visited[node] = true;
        for(auto itr:adj[node]){
            if(!visited[itr]){
                dfs(itr, visited, stk, adj);
            }
        }
        stk.push(node);
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>adj(n);
        for(auto rich:richer){
            int u = rich[0];
            int v = rich[1];
            // {u,v}, u is richer than v
            // v is less rich , u is more rich 
            //  make adj array such that for each parent node we store the child nodes that are more rich than it 
            // so for u , v is more richer  
            adj[u].push_back(v);
        }
        vector<bool> visited(n, false);
        stack<int> stk;
        for(int i=0; i<n; i++){
            if(!visited[i])
                dfs(i, visited, stk, adj);
        }

        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            ans[i] = i;
        }

        while(stk.size()){
            int node = stk.top();
            stk.pop();
            for(auto itr:adj[node]){
                if(quiet[ans[itr]]>quiet[ans[node]]){
                    // quiet of itr > quiet of self 
                    ans[itr] = ans[node];
                }
            }
        }
        return ans;
    }
}; 

//   graph is {a,b} ie a is richer than b so  a<-b
//    make graph , then find for the idx i which all are richer and among all the richer which has less quite value will be the ans
//  a person is considered as richer than itself 
//  0 -> {0,1,2,3,4,5,6}  = 5 is least quiet 
//  1 -> {1,2,3,4,5,6} = 5
//  2 -> {2}    = 2
//  3 -> {3,4,5,6}  = 5
//  4 -> {4}  = 4
//  5 -> {5} = 5
//  6 -> {6}  = 6
//  7 -> {7} = 7


// bfs
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> indeg(n,0);
        vector<vector<int>>adj(n);
        for(auto rich:richer){
            int u = rich[0];
            int v = rich[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        vector<int> ans(n,INT_MAX);
        for(int i=0; i<n; i++){
            ans[i] = i;
            if(indeg[i]==0)
                q.push(i);
        }

        while(q.size()){
            auto node = q.front();
            q.pop();
            for(auto itr:adj[node]){
                if(ans[itr]==INT_MAX || quiet[ans[itr]]>quiet[ans[node]]){
                    ans[itr] = ans[node];
                }
                indeg[itr]--;
                if(indeg[itr]==0)
                    q.push(itr);
            }
        }
        return ans;
    }
}; 


// @lc code=end


int main(){

    return 0;
}