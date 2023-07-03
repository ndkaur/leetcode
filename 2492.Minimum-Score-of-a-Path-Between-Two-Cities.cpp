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


// O(m log n), where m is the number of edges in the graph and n is the number of vertices.

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionn(int x,int y){
        x = find(x);
        y = find(y);
        if(x==y)
            return;
        if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else if(rank[y]<rank[x]){
            parent[y] =x;
        }
        else{
            parent[y]=x;
            rank[x]++;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        int sz = roads.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i] = 0;
        }
        int mn = INT_MAX;
        for(auto road:roads){
            unionn(road[0],road[1]);
        }
        for(auto road:roads){
            //1->n
            int p1 = find(1);
            int p2 = find(road[0]);
            int p3 = find(road[1]);
            if(p1==p2 && p1==p3)
                mn = min(mn, road[2]);
        }
        return mn;
    }
};





int main(){

    return 0;
}