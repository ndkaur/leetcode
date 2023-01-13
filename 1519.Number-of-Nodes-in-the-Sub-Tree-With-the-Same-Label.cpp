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


class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){ 
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n,0);
        // 0->a, 1->b, 2->a,
        find(0,adj,ans, labels);
        return ans;
    }
    vector<int> find(int curr, vector<vector<int>>& adj,vector<int>& ans, string& labels){
        vector<int> temp(26,0);
        if(ans[curr])
            return temp;
        ans[curr] = 1;
        temp[labels[curr]-'a']++;
        for(auto itr: adj[curr]){
            vector<int> res = find(itr,adj, ans, labels);
                for(int i=0; i<26; i++){
                    temp[i] += res[i];
            }
        }
        ans[curr] = temp[labels[curr]-'a'];
        return temp;
    }
};


class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){ 
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n);
        vector<int> visited(n);

        // 0->a, 1->b, 2->a,
        find(0,adj,ans,visited,labels);
        return ans;
    }
    vector<int> find(int curr, vector<vector<int>>& adj,vector<int>& ans, vector<int>& visited,string& labels){
        vector<int> temp(26);
        visited[curr] =  1;

        for(auto itr: adj[curr]){
            if(!visited[itr]){
                vector<int> res = find(itr,adj, ans, visited, labels);
                temp[labels[itr] - 'a']++;
                for(int i=0; i<26; i++){
                    temp[i] += res[i];
                }
            }
        }
        ans[curr] = temp[labels[curr]-'a'] + 1; // adding 1 fro curr count also 
        return temp;
    }
};

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        
        //creating adjacency list
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(-1,0,adj,labels, ans);
        return ans;
    }

    vector<int> dfs(int prev,int curr,vector<vector<int>>& adj,string& labels, vector<int>& ans){
        vector<int> temp(26); 
        for(auto itr:adj[curr]){
            if(prev!=itr){
                vector<int> res = dfs(curr,itr,adj,labels, ans); // prev, curr
            // combining the frequencies of left and right subtrees into one array
                for(int i=0;i<26;i++) 
                    temp[i]+=res[i];
            }
        }
        // incrementing the freq of curr node label and storing in output ans
        ans[curr] = ++temp[labels[curr]-'a'];
        return temp;
    }
};
int main(){

    return 0;
}