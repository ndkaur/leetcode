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
    void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& visited, unordered_map<int,set<int>>& mp, vector<int>& parents){
        visited[node]=1;
        // parent-> adj nodes?
        mp[par].insert(node);
        // node-> paretnt?
        parents[node] = par;

        for(auto itr:adj[node]){
            if(!visited[itr]){
                dfs(itr, par, adj, visited, mp, parents);
            }
        }
    }
    
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c+1);
        for(auto conn:connections){
            int  u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,set<int>> mp;
        vector<int> visited(c+1,0);
        vector<int> parents(c+1,0);

        for(int i=1; i<=c; i++){
            if(!visited[i]){
                // node, parent 
                dfs(i,i, adj, visited, mp, parents);
            }
        }

        vector<int> ans;
        vector<int> online(c+1,1); // in the beginning tall the componets are online
        for(auto q:queries){
            int type = q[0];
            int node = q[1];
            int parent = parents[node];
            
            if(type==1){
                if(online[node]==1){
                    ans.push_back(node);
                }
                else{ // it offline then take min node 
                    if(mp[parent].size()>0){
                        ans.push_back(*mp[parent].begin());
                    }
                    else{
                        ans.push_back(-1);
                    }
                }
            }
            else{ // type =2 , offline
                online[node]=0;
                // its offline then cant even take it as min node to revive other nodes
                mp[parent].erase(node);
            }
        }
        return ans;
    }
};

// if we store everything already then it will be eay to traverse the queires 
// we make the adj array and store all the connected components
// then do a dfs for the unvisited components and 
// along that we store all the adjacent nodes for the current parent node in a sorted set so that when 
// for a particular query we need the smallest node , we can easily get it 

int main(){

    return 0;
}