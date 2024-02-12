/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */
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

// @lc code=start


//  inituation := we need to do traversal in a particular order so topological sort will be used
//  plus one more benefit of using topo we can detect cycle and return -1 in some cases
// at each node we need to keep a track of all the colors , for each node what all max count of colors we recieved 
//  with the help of previous nodes we can find the next node's colors 
// row->nodes,  col-> colors 
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int,vector<int>> adj;
        vector<int> indeg(n,0);

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        vector<vector<int>> store(n, vector<int>(26,0));

        for(int i=0; i<n; i++){
            if(indeg[i]==0){
                q.push(i);
                store[i][colors[i]-'a'] = 1;
            }
        }

        int mx = 0; // to save the longest length 
        int cnt = 0; // to check cycle present or not

        while(q.size()){
            auto node = q.front();
            q.pop();

            cnt++;
            mx = max(mx, store[node][colors[node]-'a']);

            for(auto itr:adj[node]){
                // for each node check all chars colors
                for(int color=0; color<26; color++){
                    // u->v and color =  u(a) -> v(a) both have same color then the cnt will increase by +1 
                    // itr  = max( what itr already have , u node store + if the itr's color is same as node's color )
                    store[itr][color]  = max(store[itr][color] , store[node][color]+ (colors[itr]-'a'==color));
                }
                indeg[itr]--;
                if(indeg[itr]==0)
                    q.push(itr);
            }
        }
        if(cnt<n)
            return -1;
        return mx;
    }
};


class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(n,0);
        
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        vector<vector<int>> charcount(n,vector<int>(26,0));
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int visited=0,ans=0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited++;
            
            ans = max(ans,++charcount[curr][colors[curr]-'a']);
            
            for(auto v:graph[curr]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
                for(int i=0;i<26;i++){
                    charcount[v][i] = max(charcount[curr][i],charcount[v][i]);
                }
            }
        }
        
        if(visited!=n)
            return -1;
        
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}