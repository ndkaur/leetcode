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

class Solution{
    private:
    vector<int> topoSort(int V, vector<vector<int>>& adj){
        vector<int> indeg(V,0);
        for(int i=0; i<V; i++){
            for(auto itr: adj[i]){
                indeg[itr]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto itr:adj[node]){
                indeg[itr]--;
                if(indeg[itr] == 0)
                    q.push(itr);
            }
        }
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        // compare the strings to find the order . 
        // string that appears first caa aaa means c->a
        vector<vector<int>> adj(K);
        // we need to make a directed graph from strings 

        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2= dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int ptr = 0; ptr<len; ptr++){
                // the moment they are unqual means that will be the order 
                // abcd  abca   d!=a so  d->a
                if(s1[ptr] != s2[ptr]){
                    // aa bb a->b
                    // convert into nums value
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for(auto itr:topo){
            // convert back to chars 
            ans +=   char(itr + 'a');
        }
        return ans;
    }
};

int main(){

    return 0;
}