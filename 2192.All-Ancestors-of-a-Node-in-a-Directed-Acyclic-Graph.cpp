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


//  topological sort will give us u->v where u appears before v 
// so in that same manner we insert child for parent and grandparent for child
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        vector<set<int>> ans(n);
        while(!q.empty()){
            int sz= q.size();
            while(sz--){
                int top= q.front();
                for(auto itr:adj[top]){
                    indeg[itr]--;
                    // at child position we are inserting parent
                    ans[itr].insert(top);
                    if(indeg[itr]==0)
                        q.push(itr);
                    // child node can have parents whose parent is someone else 
                    // 1->3->5
                    for(auto itr2:ans[top]){
                        ans[itr].insert(itr2);
                    }
                }
                q.pop();
            }
        }
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++){
            for(auto j:ans[i]){
                res[i].push_back(j);
            }
        }
        return res;
    }
};

// dfs
class Solution { //O(n^2)
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> res(n);
        
        for(int i=0;i<n;i++){
            dfs(i,i,adj,res);
        }
        return res;
    }
    void dfs(int parent, int curr, vector<vector<int>>& adj, vector<vector<int>>& res){
        for(auto itr:adj[curr]){
            // if res array is empty or last ele of res is not its actual parent that means not already visited 
            if(res[itr].size()==0 || res[itr].back()!= parent){
                res[itr].push_back(parent);
                dfs(parent, itr, adj, res);
            }
        }
    }
};

int main(){

    return 0;
}