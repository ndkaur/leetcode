/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
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
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start


// we will use different dsu for alice and bob 
// first connect edge of type 3 
// every time we connect edgde using dsu we do cnt++;
// so traverse all edges and keep on increasing cnt and decresing the n val
// at the end return n-cnt  only when the connected component in both alice and bob dsu is ==1

class Solution {
public:
    int N;
    class Dsu{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        Dsu(int n){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i=0; i<n; i++){
                parent[i] = i;
                rank[i]= 0;
            }
            components=n;
        }
        int findParent(int x){
            if(parent[x]==x){
                return x;
            }
            return parent[x] = findParent(parent[x]);
        }

        void unionn(int a,int b){
            a= findParent(a);
            b= findParent(b);
            if(rank[a]<rank[b]){
                parent[a]=b;
            }
            else if(rank[b]<rank[a]){
                parent[b]=a;
            }
            else{
                parent[a]=b;
                rank[b]++;
            }
            components--;
        }

        bool isSingleComponent(){
            return components==1;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        N=n;
        int sz= edges.size();
        // type 3 edges must be connected first
        auto comp = [&](vector<int>& a, vector<int>& b){
            return a[0]>b[0]; // decreasing order
        };
        sort(edges.begin(), edges.end(), comp);

        Dsu alice(N);
        Dsu bob(N);

        int cnt =0;

        for(auto edge:edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type==3){ // common edge effect on both 
                bool checkEdgeAdded = false; 
                // if different parent then add edge increase cnt 

                if(alice.findParent(u)!=alice.findParent(v)){
                    alice.unionn(u,v);
                    checkEdgeAdded = true;
                }
                if(bob.findParent(u)!=bob.findParent(v)){
                    bob.unionn(u,v);
                    checkEdgeAdded = true;
                }
                if(checkEdgeAdded==true)
                    cnt++;
            }
            else if(type==2){
                if(bob.findParent(u)!=bob.findParent(v)){
                    bob.unionn(u,v);
                    cnt++;
                }
            }
            else{
                if(alice.findParent(u)!=alice.findParent(v)){
                    alice.unionn(u,v);
                    cnt++;
                }
            }
        }

        // if all nodes are visited all of them have only one node as parent and that means 
        //  only one component 
        if(alice.isSingleComponent()==true && bob.isSingleComponent()){
            return sz - cnt;
        }
        return -1;
    }
};



class DSU{
public: 
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x==parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unionn(int x, int y){
        int u = find(x);
        int v = find(y);
        if(u == v)
            return false;
        else{  // if not same parent
            if(rank[u]<rank[v])
                parent[u] = v;
            else if(rank[v]<rank[u])
                parent[v] = u;
            else{
                parent[v] =u;
                rank[u]++;
            }
            return true;
        }
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // type 1 , type 2 , type 3 
        // but we want the type 3 alice and bob to be added first 
        // so sort the array on basis of type 3
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0] > b[0]; // decresing order 3 2 1
        });

        DSU dsu_alice(n+1);
        DSU dsu_bob(n+1);

        int removed_edge =0;
        int alice_edge =0;
        int bob_edge =0;

        for(auto edge:edges){
            if(edge[0] == 3){ // type 3 both alice and bob
                // check for already a union exist in alice tree
                if(dsu_alice.unionn(edge[1], edge[2])){
                    // if yes for alice union tree then join bob also
                    dsu_bob.unionn(edge[1], edge[2]);
                    alice_edge++;
                    bob_edge++;
                }
                else{
                    removed_edge++;
                }
            }
            else if(edge[0] == 2){ //type 2 only bob  
                if(dsu_bob.unionn(edge[1], edge[2])){
                    bob_edge++;
                }
                else{
                    removed_edge++;
                }
            }
            else{ // type 1 only alice
                if(dsu_alice.unionn(edge[1], edge[2])){
                    alice_edge++;
                }
                else{
                    removed_edge++;
                }
            }
        }
        // now if alice and both cnt is n-1 
        return (bob_edge == n-1 && alice_edge == n-1) ? removed_edge : -1;
    }
};
// @lc code=end


int main(){

    return 0;
}