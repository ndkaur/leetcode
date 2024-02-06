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


// 1->  we want to sort on basis of weight but it will interchange the actual indexes 
// so add indexes in the edges also 
// 2 -> sort on basic of weight 
// 3 -> find mst weight using all edges 
// 4 -> check for each edge if removeing it following of any case happens
//  a) if the weight we got after removing the current edge increased  mst < newWt  then this edge is critical 
//  b) partial critical is we can remove or add it but the weight doesnt change , we already checked by removing 
//    so add the edge find weight if remians same that edge is partial 
//  add the idx in the vector< ans> 

//  krushkal using  and mst 

class Solution {
public:
    int N;
    // kruskal is getting called multiple times so for each tme paretn and rank will be different so use class of union find
    class UnionFind{
    public: 
        vector<int> parent;
        vector<int> rank;
        
        UnionFind(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i=0; i<n; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findParent(int u){
            if(parent[u]==u)
                return u;
            return parent[u] = findParent(parent[u]);
        }

        void unionn(int x, int y){
            x = findParent(x);
            y = findParent(y);

            if(x==y) // already connected
                return;
            
            // connect
            if(rank[x]<rank[y]){
                parent[x] = y;
            }
            else if(rank[y]<rank[x]){
                parent[y] = x;
            }
            else {
                parent[x] = y;
                rank[y]++;
            }
        }
    };

    int kruskal(vector<vector<int>>& edges, int skip, int add){
        int wt = 0;

        // union find class object
        UnionFind uf(N);

        // edge -> { u, v, wt, idx}
        // add edge case using dsu
        if(add!=-1){
            uf.unionn(edges[add][0], edges[add][1]);
            wt += edges[add][2];
        }

        for(int i=0; i<edges.size(); i++){
            if(i==skip) // skiping it not adding in dsu 
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int parentU = uf.findParent(u);
            int parentV = uf.findParent(v);

            if(parentU!=parentV){ // not connected
                uf.unionn(u, v); // connect them
                wt += w;
            }
        }

        // but sometimes it can happen that actual mst is not formed properly 
        // instead of a single connected component we are having multiple components
        // so check if only single parent exist and eaxh node has one same parent 
        // fix any node and check its parent with each other node 
        //if at any point both parents become unequal it means not a proper mst

        for(int i=0; i<N; i++){
            if(uf.findParent(i)!=uf.findParent(0))
                return INT_MAX;
        }

        return wt;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i=0; i<edges.size(); i++){
            edges[i].push_back(i);
        }

        auto comp = [&](vector<int>& a, vector<int>& b) {
            return a[2] < b[2]; // ascending order
        };
        sort(edges.begin(), edges.end(), comp);
        
        // sometimes skip and add edge 
        int mstWt = kruskal(edges,-1, -1); // edge, skip , add

        vector<int> critical;
        vector<int> pseudo_critical;

        for(int i=0; i<edges.size(); i++){
            if( mstWt < kruskal(edges, i, -1)){ // skipping ith edge cause increase in weight 
                critical.push_back(edges[i][3]); // adding the idx 
            }
            else if(kruskal(edges, -1, i)==mstWt){ // adding ith edge
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo_critical};
    }
};


int main(){

    return 0;
}