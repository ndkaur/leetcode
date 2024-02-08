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


// brute force :- use dfs from each node and store its result
// time-> N node * (O(N) dfs) ~ O(N*N) 


// in this method folow these steps
// 1)  find the cnt for root node using dfs1
// 2) in the same dfs1 we need to fill the count vector 
//  count vector store the cnt of the children of the current node including the curr node 
// why we need the count vector?  cause if we dry run we found that 
// suppose if root node has some distance val as 12 , then its child distance from other nodes we can calculate using the ans of parent 
// the formula is :- 
    //  distance of child  = distance of parent - (no of children of child node including itself ) + the remaining nodes which are not the children of child node 

// so after find distance of root , and filling the count vector we need to perform next step

//  3) now start a dfs2 , go on each node and use the formula and fill the ans array
// return the ans array 


class Solution {
public:
    int dfs(int node, int prev, int depth, vector<vector<int>>& adj, vector<int>& cnt, long& rootAns){
        int total = 1; // each curr node has itself    
        rootAns += depth; // add depth at begining cause that the distance of root to each node 
        for(auto itr:adj[node]){
            if(itr==prev) // so that we dont keep on visitng the same nodes again n again 
                continue;
            total += dfs(itr, node, depth+1, adj,cnt, rootAns);
        }
        cnt[node] = total;
        return total; // we need to return so that the prev dfs call can add the result value in it 
    }

    void dfs2(int node, int prev, int n,  vector<vector<int>>& adj, vector<int>& cnt, vector<int>& ans){
        for(auto itr:adj[node]){
            if(itr==prev)
                continue;
            ans[itr] = ans[node] - cnt[itr] + (n-cnt[itr]);
            dfs2(itr, node, n, adj, cnt, ans);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> cnt(n,0); // stores the cnt of the childdren of the curr node
        long  rootAns = 0; // distance sum of root from all nodes 
        // curr_node, prev_node, depth, adj, cnt array, root_distance 
        dfs(0, -1, 0, adj, cnt, rootAns);

        vector<int> ans(n,0);
        ans[0] = rootAns;
        dfs2(0, -1, n, adj, cnt, ans);
        return ans;
    }
};


int main(){

    return 0;
}