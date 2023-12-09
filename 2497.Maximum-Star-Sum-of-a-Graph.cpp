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
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<priority_queue<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push(vals[v]);
            adj[v].push(vals[u]);
        }
        int ans = INT_MIN;
        // sum = original node val + all adj nodes val
        for(int i=0; i<adj.size(); i++){
            int temp = vals[i];
            int t = k;
            ans = max(ans, temp);
            while(adj[i].size() && t){
                temp += adj[i].top();
                // find max alongside cause what if the next val is -ve and it makes overall sum less
                ans = max(ans, temp);
                adj[i].pop();
                t--;
            }
        }
        return ans;
    }
};

// time complexity  
// traversing through all the nodes * [going through all the adjacent nodes of a specific node * (adding them to a priority queue) + emptying the priority queue which will have a size of K] = O(N * [No. of adj Nodes of a given node * (log(No. of adj nodes)) + K])
// combining these two we get
// -- O(E) + O(N * (ADJ * log(ADJ)+ K))

int main(){

    return 0;
}