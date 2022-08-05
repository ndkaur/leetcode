/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto p:paths){
            int u = p[0];
            int v= p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n);
        for(int i=1;i<=n;i++){ // nodes 
            vector<int> color(5,0);
            for(auto itr:adj[i]){
                color[ans[itr-1]]=1; // color used by child itr
                // used so mark 1 so cant use again
            }
            for(int j=1;j<=4;j++){ // check which color is left
                if(color[j]==0){ // not use 
                    ans[i-1]=j; // use it 
                    break;
                }
            }
        }
        return ans;
    }
};

// using concept of colouring birpartite graph 
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<paths.size();i++){
            int u= paths[i][0];
            int v= paths[i][1];
            // zero based indexing in adj list but the garph has nodes starting from 1 
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]!=0){
               continue;
            }
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int node= q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(color[it]==0){
                        color[it] = (color[node]==4) ? 1 : color[node]+1;
                        q.push(it);
                    }
                    else if(color[it]==color[node])
                        color[it] = (color[node]== 4) ? 1 : color[node]+1;
                }
            }
        }
        return color;
    }
};


// @lc code=end


int main(){
    Solution sol;
    int n=3;
    vector<vector<int>> path={{1,2},{2,3},{3,1}};
    vector<int> ans = sol.gardenNoAdj(n, path);
    print(ans);
   return 0;
}