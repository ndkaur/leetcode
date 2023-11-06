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


// so the main idea is we chose any node add its value to our ans and then change its value to 0 .. after this whole process we see if the root to leaf path the sum is 0 
// so the intitution is we can only change the root if changed root then cant change the child cause this way the path sum will become zero 
// and if we change the child nodes then we cant change the root node 
// so max score  = total - min score of (make parent 0 , make child 0) 

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long sum =0;
        for(int value:values){
            sum += value;
        }

        vector<int> visited(n,0);
        long long k = dfs(0, adj, values, visited);
        return sum - k;
    }
    long long dfs(int i, vector<vector<int>>& adj, vector<int>& values, vector<int>& visited){
        // if the adj list has only one node ie it is the leaf node
        if(adj[i].size()==1 && i!=0)
            return (long long)values[i];
        
        long long sum =0;
        visited[i] = 1;
        
        for(auto itr:adj[i]){
            if(visited[itr]==1)
                continue;
            
            sum += dfs(itr, adj, values, visited);
        }
        
        return min((long long)values[i], sum);
    }
};

int main(){

    return 0;
}