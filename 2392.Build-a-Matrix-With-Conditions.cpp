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
     vector<int> topoSort(int k, vector<vector<int>> edges){
        vector<vector<int>> adj(k+1);
        vector<int> indeg(k+1,0);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i=1; i<=k; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(q.size()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto itr:adj[node]){
                indeg[itr]--;
                if(indeg[itr]==0){
                    q.push(itr);
                }
            }
        }
        return topo;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<int> rowOrder = topoSort(k,row);
        vector<int> colOrder = topoSort(k,col);

        // if cycel is present no indeg will able to reduce so few elem added and no answer will be possible 
        if(rowOrder.size()!=k || colOrder.size()!=k) 
            return {};

        vector<vector<int>> ans(k, vector<int>(k,0));

        vector<int> store(k+1,0);
        for(int j=0; j<colOrder.size(); j++){
            store[colOrder[j]] = j;
        }
        for(int i=0; i<k; i++){
            ans[i][store[rowOrder[i]]] = rowOrder[i];
        }
        return ans;
    }
};



int main(){

    return 0;
}