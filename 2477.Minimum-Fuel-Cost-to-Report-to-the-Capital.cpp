#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
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
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<vector<int>> adj(n+1);
        for(auto road:roads){
            int u = road[0];
            int v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n+1,0);
        long long ans = 0;
        dfs(0,ans,seats,visited,adj);
        return ans;
    }
    long long dfs(int node, long long& ans, int seats, vector<int>& visited, vector<vector<int>>& adj){
        visited[node] = 1;
        long long count = 1;
        for(auto itr:adj[node]){
            if(!visited[itr]){
                count += dfs(itr,ans,seats,visited, adj);
            }
        }
        long long no_of_people_that_can_go = count/seats;
        // no of remaining people that are left 
        if(count%seats)
            no_of_people_that_can_go++;

        if(node!=0) // if node os other than source node then add the count of peopel to ans
            ans += no_of_people_that_can_go;

        return count;
    }
};

// adj list 
// 0 -> 1,4,5
// 1 -> 0,3
// 2 -> 3
// 3 -> 1,2
// 4 -> 0,6
// 5 -> 0
// 6 -> 4

// first for 0  cnt += dfs(adj->itr)
// 1+dfs(1)
// 1+dfs(3)
// 1+dfs(2) 
// // 2 adj is 3 which is already visited so 
// 1+dfs(2) = 1+0= 1   
// no of people =  count/seats = 1/2 = 0 
// 1%2 = 1 so  people++ = people = 1
// ans = 1

// 1+dfs(3) = 1+1 = 2 
// people = 2/2 = 1
// ans = 1+1

// 1+dfs(1) = 1+2 =3
// people = 3/2 = 1
// 3%2 = people = 2 
// ans = 1 + 1 + 2  = 4 from the call of dfs(1) subtree


// now call of adj of 0 ie 4
// 1+dfs(4)
// 1+dfs(6) 
// cnt =1 

// 1+dfs(6) =1 
// 1/2 = 0
// 1%2 = 1 
// people =1 
// ans = 1 

// 1+dfs(4) = 1+1 =2 
// 2/2 =1 
// people =1 
// ans = 1+1 =2   from the call of dfs(4) substree

// now call for adj of 1 ie 5
// 1+dfs(5) = 1+0 = 1 
// 1/2 =0
// 1%2 =1
// people =1
// ans =1  from the call of dfs(5) subtree 

// rest all nodes got visited 

// so total ans = 4+2+1 = 7 
