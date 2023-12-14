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
    int edgeScore(vector<int>& edges) {
        int n= edges.size();
       vector<unsigned int> indeg(n,0);
        for(int i=0; i<n; i++){
           indeg[edges[i]] += i;
        }
        int idx=0;
        unsigned int mx=0;
        for(int i=0;i<indeg.size();i++){
           if(mx<indeg[i]){
               mx= indeg[i];
               idx=i;
           }
            
        }
        return idx;
    }
};


class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            // u->v 
            int u =i;
            int v = edges[i];
            adj[v].push_back(u);
        }
        long long mx =0;
        int node;
        for(int i=0; i<n; i++){
            long long sum =0;
            for(auto itr:adj[i]){
                sum+=itr;
            }
            if(mx<sum){
                mx = sum;
                node = i;
            }
        }
        return node;
    }
};


int main(){

    return 0;
}