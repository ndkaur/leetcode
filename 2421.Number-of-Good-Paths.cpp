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