/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
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
class Solution0 { // khans algo 
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num,0);
        for(auto p:pre){
            int course= p[0];
            int depend= p[1];
            adj[course].push_back(depend);
            indegree[depend]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return count==num;
    }
};


class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> color(num);
        bool has_cycle;
        for(auto p:pre){
            adj[p[0]].push_back(p[1]);
        }
        has_cycle=false;
        for(int i=0;i<num;i++){
            if(color[i]==0)
                dfs(i,adj,color,has_cycle);
            if(has_cycle) return false;
        }
        return !has_cycle;
    }
    void dfs(int x, vector<vector<int>>& adj,vector<int>& color, bool &has_cycle){
        color[x]=1;
        for(auto it:adj[x]){
            if(color[it]==0)
                dfs(it,adj,color, has_cycle);
            else if(color[it]==1)
                has_cycle = true;
        }
        color[x]=2;
    }
};

// @lc code=end


int main(){
    Solution sol;
    int num=2;
    vector<vector<int>> pre={{1,0}};
    bool ans = sol.canFinish(num,pre);
    cout<<ans;
   return 0;
}