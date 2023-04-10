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