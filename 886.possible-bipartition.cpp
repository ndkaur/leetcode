/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
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
    bool Bipartite(vector<vector<int>> &adj,vector<int> &color,int src){
        queue<int> q;
        q.push(src);
        color[src]=1;
    
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(Bipartite(adj,color,i)==false)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> dislikes={{1,2},{1,3},{2,4}};
    int n = 4;
    bool ans= sol.possibleBipartition(n,dislikes);
    cout<<ans;
   return 0;
}