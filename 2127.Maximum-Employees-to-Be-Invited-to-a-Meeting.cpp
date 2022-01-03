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

// the solution is mixture of two approaches 
// 1 is to find the lenght of the longest cycle formed 
// 2 is to find the two way nodes and then finding their reapective max attached lenghts 

class Solution0 {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<vector<int>> rev(n);
        for(int i=0; i<n; ++i){
            rev[fav[i]].push_back(i);
            // deb(i, fav[i]);
            // cout<<i<<" "<<fav[i]<<"\n";
        }
        int ans = 0;
        vector<int> color(n), dp(n);
        
        function<void(int)> dfs = [&](int node){
            color[node] = 1;
            int ad = fav[node];
            if(color[ad]==0)
                dfs(ad);
            else if(color[ad]==1){
                int st = ad, len = 1;
                while(st!=node){
                    ++len;
                    st = fav[st];
                }
                ans = max(len, ans);
            }
            color[node] = 2;
        };

        for(int i=0; i<n; ++i){
            if(color[i]==0){
                dfs(i);
            }
        }

        function<int(int,int)> dfs2 = [&](int node, int p){
            int len = 0;
            for(auto ad: rev[node]){
                if(ad==p) continue;
                len = max(len, dfs2(ad, node));
            }
            return len+1;
        };

        int cur = 0;
        for(int i=0; i<n; ++i){
            if(i==fav[fav[i]] && i>fav[i]){
                cur+=dfs2(i,fav[i]) + dfs2(fav[i], i);
            }
        }

        // deb(ans);

        return max(ans, cur);
    }
};


class Solution {
public:
    void dfs(int node, vector<bool>& visited , vector<bool>& dfsvis, vector<int>&par,vector<int> adj[] , int &ans){
        visited[node]= dfsvis[node]=true;
        for(auto& itr:adj[node]){
            if(!visited[itr]){
                par[itr] = node;
                dfs(itr,visited, dfsvis, par,adj, ans);
            }
            else if(dfsvis[itr]){
                // lenght of cycle 
                int vertex= node;
                int count=1;
                while(vertex!=itr){
                    count++;
                    vertex = par[vertex];
                }
                ans = max(ans, count); // max of all cycles 
            }
        }
        dfsvis[node] = false; // so that can revisit 
    }

    int maximumInvitations(vector<int>& favorite) {
        int n= favorite.size();
        vector<int> adj[n];
        vector<int> par(n,-1);
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            adj[i].push_back(favorite[i]);
            indegree[favorite[i]]++;
        }
        vector<bool> visited(n);
        vector<bool> dfsvis(n);
        int ans =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,dfsvis,par,adj,ans);
            }
        }
        // finfing cycle of lenth 2 // topo sort khans algo 
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> dp(n,1);
        while(!q.empty()){
            int v= q.front();
            q.pop();
            for(auto& itr:adj[v]){
                indegree[itr]--;
                if(indegree[itr]==0)
                    q.push(itr);
                dp[itr] = max(dp[itr], 1+dp[v]);
            }
        }

        int sum=0;
        for(int i=0;i<n;i++){
            if(favorite[favorite[i]]==i){ // lenght 2 cycle
                // a-> is fav of-> b and b->is fav of-> a
                sum+= dp[i]+ dp[favorite[i]]; // sum of two arms 
            }
        }
        sum /=2;
        ans = max(ans, sum); // amx of both 2 type of cycles
        return ans;
    }
};



int main(){
    Solution sol;
    vector<int> fav={2,2,1,2};
    int ans = sol.maximumInvitations(fav);
    cout<<ans;
   return 0;
}