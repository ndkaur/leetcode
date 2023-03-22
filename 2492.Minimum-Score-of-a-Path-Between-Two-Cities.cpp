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
    int minScore(int n, vector<vector<int>>& roads) {
        int sz = roads.size();
        vector<int> visited(n+1,0);
        int mn = INT_MAX;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        queue<int> q;
        q.push(1);
        visited[1] = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto itr:adj[node]){
                mn = min(mn, itr.second);
                if(!visited[itr.first]){
                    visited[itr.first] =1;
                    q.push(itr.first);
                }
            }
        }
        return mn;
    }
};


int main(){

    return 0;
}