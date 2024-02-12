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


// similar to binary tree max path sum 
class Solution0 {
public:
    int dfs(int curr, int parent, unordered_map<int, vector<int>>& adj, int& mx, string& s){
        int first = 0;
        int second = 0;
        for(auto itr:adj[curr]){
            if(itr==parent)
                continue;
            int childPath = dfs(itr, curr, adj, mx, s);

            if(s[itr]==s[curr])
                continue;
            
            if(childPath > second)
                second = childPath;
            if(second>first)
                swap(first, second);
        }

        mx = max(mx, 1 + first + second);
        return 1+max(first, second);
       
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mx = INT_MIN;
        dfs(0, -1, adj, mx, s);
        return mx;
    }
};



// similar to binary tree max path sum 
class Solution {
public:
    int dfs(int curr, vector<vector<int>>& adj, int& mx, string& s){
        // same as tree we dont have left and right child so use first and second 
        // as the max values got from the adjacent nodes of the curr node
        int first = 0;
        int second = 0;
        for(auto itr:adj[curr]){
            int childPath = dfs(itr, adj, mx, s);

            if(s[itr]==s[curr]) // same char then dont include in path 
                continue;
            
            if(childPath > second)
                second = childPath;
            if(second>first)
                swap(first, second);
        }

        mx = max(mx, 1 + first + second); // prev ans , curr subTree 
        return 1+max(first, second); // taking the new full tree path 
       
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        // parent->node
        // parent[i] -> i
        // but parent[0]= -1 cause 0 has no parent so start loop from i=1
        for(int i=1; i<n; i++){
            // directed graph , parent->ith node
           adj[parent[i]].push_back(i);
        }
        // using same code as binary tree max path sum
        int mx = INT_MIN;
        dfs(0, adj, mx, s);
        return mx;
    }
};


class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }
        int ans = 1; 
        vector<int> dist(n);
        dfs(0, s, adj, ans, dist);
        return ans;
    }
    void dfs(int curr, string& s, vector<vector<int>>& adj, int& ans, vector<int>& dist){
        dist[curr] = 1;
        for(auto itr:adj[curr]){
            dfs(itr,s,adj,ans, dist);
            if(s[itr] != s[curr]){
                ans = max(ans, dist[curr] + dist[itr]);
                dist[curr] = max(dist[curr], dist[itr]+1);
            }
        }
    }
};


int main(){

    return 0;
}