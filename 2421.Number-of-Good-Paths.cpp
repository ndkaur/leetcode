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
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionn(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b)
            return;
        if(rank[a]<rank[b]){
            parent[a]=b;
        }
        else if(rank[b]<rank[a]){
            parent[b] = a;
        }
        else{
            parent[b] = a;
            rank[a]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // we need to store for val which all nodes share the same value , so use map
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[vals[i]].push_back(i);
        }

        int ans = n;

        // now simply pick the paths in greedy manner 
        // values in map are stored in increasing order so pick val and then pick nodes related to it 
        for(auto val:mp){
            for(auto node:val.second){
                for(auto itr:adj[node]){
                    if(vals[itr]<=vals[node]){
                        // then perform union
                        unionn(itr, node);
                    }
                }
            }
            // now if union happened , good path only be formed when 
            // 1. all nodes have vals less than start -> this alredy satisfied above
            // 2. the start and end node is same -> so to satisfy this 
            //  we need to find the count of each node in the union set 
            //  so its better to find the count of the parent and how many nodes they have against them 
            // after each possible union we need to check what is the cnt of the same parents 
            // so find that we use map 
            map<int,int> freqParent;
            for(auto node:val.second){
                int p = find(node);
                freqParent[p]++;
            }

            // in a union set suppose there is only one cnt of 3 -> then good path =1
            //  two count of 3 as parent -> then good path =2
            // three count of 3 as parent -> then 3 good path 
            // so 1, 2, 3 .... so the no of good path = (n*(n-1))/2
            for(auto itr:freqParent){
                int par = itr.first;
                int cnt = itr.second;
                ans += (cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};


// o(nlogn)
class Solution {
public:
    vector<bool> visited;
    vector<int> parent;

    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionn(int a, int b){
        int a1 = find(a);
        int b1 = find(b);
        if(a1 == b1) 
            return;
        parent[a1] = b1;
    }

	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        visited.resize(n, false);

        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i; // parent of i is i itself
        }
        
        vector<vector<int>> adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        map<int,vector<int>> mp; // val ->{nodes with same values}
        for(int i=0; i<n; i++){
            mp[vals[i]].push_back(i);
        }

        int cnt = n; // including the single nodes aswell
        
        for(auto m : mp){ // val
            for(auto &u : m.second){ // array
                visited[u] = true; // mark the node as visited
                for(auto &v : adj[u]){ // each adj to the node 
                    if(visited[v]){ // if the nodes adjacents are also visited then connect them 
                        unionn(v,u);
                    }
                }
            }

            unordered_map<int,int> freq; // for each val new map will be created 
            for(auto &u : m.second){ // for each values array count freq 
                int p = find(u);
                freq[p]++;
            }

            for(auto [key,value] : freq){ // freq is the count of the number of times a particular val exist in union of graph 
                cnt += (value*(value-1))/2;
            }
        }
        return cnt;
	}
};

// adj 
// 0 -> {1,2}
// 1 -> {0}
// 2 -> {0,3,4}
// 3 -> {2}
// 4 -> {2}

// map of {val, node}
// 1 -> {0,3}
// 2 -> {2}
// 3 -> {1,4}


// visited arary 
// 0 1 2 3 4 
// T   T T

// first iteration with val = 1 
// {0,3} 
// choose 0 -> adj {1,2} , mark 0 as true
//  1 and 2 both not visited so no union 
// choose 3 ->adj {2} , mark 3 as true
//  2 is also not visited no union 

// second iteration for val =2
// {2} mark 2 as true
// adj of 2 {0,3,4}
// 0 1 2 3 4 
// T   T T
// 0 is visted , so union 0
// 3 is visted , so union 0->3
// map freq find(2) = 2 freq of 2 =1  cnt =0

// third iteration for val =3
// {1,4}
// 0 1 2 3 4 
// T T T T T
// adj of 1 {0} , mark 1 as true
// 0 is also visited so union of (0,1) 0->1
// adj of 4 {2} , mark 4 as visited 
// 2 is also visited so union of (4,2) 2->4

// map freq ->{1,4}
// find(1)  = 0 
//  find(4) = find(2) = 0 
// freq[0] = 2 
// cnt = 2 *(2-1) = 2/2 =1 
// cnt = n+1 = 5+1 = 6

int main(){

    return 0;
}