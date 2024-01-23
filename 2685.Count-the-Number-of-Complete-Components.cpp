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

//bfs

// we only want to count the fully connected components 
// simple bfs will cnt only all the componects if if they are not completely connected 
//so to check if the cnt only increases when the components are completely connected to each other 
class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& visited, int& ans){
        queue<int> q;
        q.push(node);
        visited[node] =1;
        int cnt = 0; // cnt only increase wehen we pop 
        int edgecnt = 0;
        while(q.size()){
            auto node = q.front();
            q.pop();
            cnt++;
            for(auto itr:adj[node]){
                if(!visited[itr]){
                    q.push(itr);
                    visited[itr]=1;
                }
                edgecnt++; // when each adjacent of the curr node is visited the edgecnt increases 
                // this states the cnt of the nodes visited each time even in repeatance in the component by diffrent itr parents
            }
        }
        if(cnt*(cnt-1)==edgecnt) 
            ans++;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(i,adj, visited,cnt);
            }
        }
        return cnt;
    }  
};


// dfs
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        // a componnet is only considered connected when 
        // the size of its path formed during dfs on its adj[its]
        // and the size of full path is equal 
        // means in components if one comp has 2 children other should also have 2 so that they can become conneected
        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                vector<int> path;
                dfs(i,adj,path,visited);
                int cnt =0;
                for(int j=0; j<path.size(); j++){
                    //path ={0,1,2}
                    // 0->1,2 adj 
                    // adj[path[j]] = adj[path[0]].size() >= path.size()-1
                    // 2 >= 2
                    if(adj[path[j]].size() >= path.size()-1)
                        cnt++;
                    if(path.size()==cnt)
                        ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int i, vector<vector<int>>& adj,vector<int>& path, vector<int>& visited){
        visited[i] = 1;
        path.push_back(i);
        for(auto itr:adj[i]){
            if(!visited[itr]){
                dfs(itr,adj,path, visited);
            }
        }
    }
};

// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]

// adj list
// 0 -> 1,2
// 1-> 0,2
// 2-> 0,1
// 3-> 4,5
// 4-> 3
// 5-> 3

// dfs(0)->dfs(1)->dfs(2) path={0,1,2}  path.size()-1 =2
// adj[path[0]].size() = adj[0].size() = 2 >=2  cnt =1
// adj[path[1]].size() = 2>=2 cnt =2
//adj[path[2]].size() = 2>=2 cnt=3 
// cnt == path.size() = ans++ = ans=1

// dfs(3)->dfs(4)->dfs(5) path={3,4,5} path.size()-1 = 2
// adj[path[0]].size() = adj[3].size() = 2   2>=2 cnt =1
//adj[path[1]].size() = adj[4].size() = 1  1!>2 
//adj[path[2]].size() = adj[path[5]].size() = 1 !>2
// cnt =1 path.size() =3 so no ans increment

// ans= 1








int main(){

    return 0;
}