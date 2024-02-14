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


// when we decide to remove node one by one then we get some remaining nodes
// remove 0 -> reming {1,2}
//  remove 1 -> remiang {0,2}
//  remove 2 -> {0,1} 
// remove {0,1} -> {2}
//  remove {0,2} -> {1}
// remove {1,2} -> {0}
//  remove {} -> {0,1,2} 
//  so if we see that the remaining nodes collectively make the subsets of n 
//  so one approach is we find all the subsets then for each subset we check the edges of graph 
// eg: - {2}  then roads that can be made -> 2  valid 
//  eg:- {1,2} then roads 1->2  but dist is 10 so not valid
// eg:- {0,1} then roads 0->1 dist = 2 valid 
// but this will take alot of time 
//  so use bitmask to store subsets ehose range will be from 0 to 2^n -1
// for each subset check each graph path , if both u and v are setbits then 
//  check distance of u -> v shortest distance 
// next use floyd warshall to find distance
//  check if dist formed is less than max then cnt++


class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int cnt = 0;
        //  0 -> 2^n -1 
        //checking for each subset of n length 
        for(int set=0; set < (1<<n); set++){
            // making graph matrix cause we can easily use floyd warshall algorithm 
            vector<vector<int>> adj(n, vector<int>(n, 1e9));
            // i -> i dist is 0
            for(int i=0; i<n; i++){
                adj[i][i] = 0;
            }

            // for each edge check set value
            for(auto road:roads){
                int u = road[0];
                int v = road[1];
                int wt = road[2];
                // check if u and v is setbit in set
                // checking if our curr subset contians the u and v node or not 
                if((set>>u)&1 && (set>>v)&1){
                    // same node can have two distances so we use the min distance 
                    adj[u][v]  = min(adj[u][v],wt);
                    adj[v][u] = min(adj[u][v], wt);
                }
            }

            // finding shortest dist from each node to each other node
            for(int k =0; k<n; k++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }

            // now check if u->v shortest path is less than max dist given 
            // in our matrix check those min than maxDist 
            bool valid = true;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) // diagonals skip 
                        continue;
                    if((set>>i)&1 && (set>>j)&1){// checking if the subset in in grpah or not 
                        if(adj[i][j]>maxDistance){
                            valid = false;
                            break;
                        }
                    }
                }
            }

            if(valid)
                cnt++;
        }
        return cnt;
    }
};



int main(){

    return 0;
}