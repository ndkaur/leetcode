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

// soin a path of trip , we can pick only those nodes which are non adjacent to each other 
//  and after picking them use the half weight of its 
//brute force -> each node has 2 options 2^n 
// we need to traverse for each trip that will take alot of time 
// so we need to stroe each trip used nodes in a single array eaar
// so we need to use dp -> but for that we need to know which node is ocuuring how many times
//  in each trip how many nodes are coming how many times store it in an array 
// 0 1 2 3
// 1 3 2 2  

class Solution {
public:
    int dfs(int node, int parent, int parentHalf, vector<int>& cnt, vector<int>& price, vector<vector<int>>& adj, vector<vector<int>>& dp){
        int pick = (cnt[node]*price[node])/2; // pick then price half 
        int notPick = cnt[node]*price[node]; // no half price add full

        if(dp[node][parentHalf]!=-1)
            return dp[node][parentHalf];

        for(auto& itr:adj[node]){
            if(itr!=parent){ // check if that node is valid 
                notPick += dfs(itr, node, 0, cnt, price, adj, dp);
            }
        }

        // if the parent is already picked then we cant pick its adj nodes so store directly in dp and return 
        // the loop for pick will not work 
        if(parentHalf==1)
            return dp[node][parentHalf] = notPick;
        

        for(auto& itr:adj[node]){
            if(itr!=parent){
                pick += dfs(itr, node, 1, cnt, price, adj, dp);
            }
        }

        return dp[node][parentHalf] =  min(pick, notPick);
    }

    void findCntDFS(int node, int dest, int parent, vector<int>& curr, vector<int>& cnt, vector<vector<int>>& adj){
        curr.push_back(node);
        
        if(node==dest){ // destination reached , increased cnt of all nodes inbetween
            for(auto& i:curr){
                cnt[i]++;
            }
            // we reached dest and now need to ecplore other paths 
            curr.pop_back();
            return;
        }
        
        for(auto& itr:adj[node]){
            if(itr!=parent){
                findCntDFS(itr, dest, node, curr, cnt, adj);
            }
        }
        // backtrack if cant reach destination or try another path 
        curr.pop_back();
        return;
    }


    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> cnt(n,0); // count of each node in each trip 
        for(auto t:trips){
            vector<int> curr; // to keep check of what all nodes lies between t[0] -> t[1]
            findCntDFS(t[0], t[1], -1, curr, cnt, adj);
        }
        // after this we have our cnt array filled 
        // use dp to check pick and not pick on non adjacent nodes
        vector<vector<int>> dp(n+1, vector<int>(2,-1)); 
        //  just like in buy sell stock 
        //  we have two iptions buy or sell so we pass array with size 2 and a bool buy that tell wether we can buy now or not  
        return dfs(0, -1, 0, cnt, price, adj, dp);
    }
};



int main(){

    return 0;
}