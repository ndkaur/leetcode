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

// firstly the bob goes from a path where source is fixed as bob and destination is fixed as 0 -> so we will do a dfs on bob path and store its time at each node in a map 
// then we will move from 0 to all the leaf nodes and caluclate the path income for alice by comping bob time and other conditions

class Solution {
public:
    bool dfs(int src, int time, unordered_map<int,int>& mp, vector<int>& visited, vector<vector<int>>& adj){
        mp[src] = time;
        visited[src] = 1;
        if(src==0) // reached destination
            return true;
        for(auto itr:adj[src]){
            if(!visited[itr]){
                if(dfs(itr, time+1, mp, visited, adj)){
                    return true;
                }
            }
        }
        mp.erase(src);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // we also want to store time of when it is at each node 
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // map to store that at what time bob is at what node 
        unordered_map<int,int> mp; // node , time 
        vector<int> visited(n,0);
        dfs(bob, 0, mp, visited, adj); // src, time , map

        // now after dfs we will know at what time bob is at what node 
        // so now start moving alice and calulate its profit 
        // bfs 
        queue<vector<int>>q; // src, time, income
        q.push({0,0,0});
        visited.assign(n, 0);
        int ans = INT_MIN;

        while(q.size()){
            int node = q.front()[0];
            int time = q.front()[1];
            int income = q.front()[2];
            q.pop();
            
            visited[node]=1;
            
            // now check if bob had visited that path or not 
            // and if visited then before or after alice 
            if(mp.find(node)==mp.end()){ // alice first to come 
                income += amount[node];
            }
            else{ // bob already visited 
                // if alice visited first 
                if(time < mp[node]){
                    income += amount[node];
                }
                // both visited at same time
                else if(time==mp[node]){
                    income += (amount[node]/2);
                } 
                // bob visited first 
                // then no income will be added to alice
            }
            // check if alice reached the leaf then calculate the max ans 
            // leaf node is that which has only one adj ie its parent 
            // 0 can also be misintepreted as leaf node but we dont want it 
            if(node!=0 && adj[node].size()==1){
                ans = max(ans, income);
            }
            // checking its adj 
            for(auto itr:adj[node]){
                if(!visited[itr]){
                    q.push({itr, time+1, income});
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}