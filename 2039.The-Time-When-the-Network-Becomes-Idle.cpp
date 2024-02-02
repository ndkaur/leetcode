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
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        int n = pat.size();
        
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(n,-1);
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0]=1;
        dist[0] = 0;

        // now after this we will know the dist of each node from source 0
        while(q.size()){
            auto node = q.front();
            q.pop();
            for(auto itr:adj[node]){
                if(!visited[itr]){
                    dist[itr] = 1+dist[node];
                    visited[itr] =1;
                    q.push(itr);
                }
            }
        }

        // now we need to find that when the last packet was released from all the nodes 
        //  add 2*(dist of node) and then find max of all

        // Number of message relased(mess_count) = 2*(Distance of Node) / patience[i]
        // if patience[i] divides completely 2*(Distance of Node ) then one less message will be 
        // released as at that time the node will get the message back from source
        
        int ans = 0;
        for(int i=1; i<n; i++){
            int d = dist[i];
            int curr =0;
            if(pat[i]==0)
                curr = (4*d-1);
            else{
                int num = (2*d)/pat[i];
                if((2*d)%pat[i]==0)
                    num--;
                curr = pat[i]*num + 2*d;
            }
            ans = max(ans, curr);
        }
        return ans+1;
    }
};

int main(){

    return 0;
}