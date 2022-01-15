/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start

// till  size is greter than 2 keep on removing nodes with degree 1
// the node with indegreee 1 is the ans 

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans; 
        
        for(auto &e : edges){   
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n;i++){
            if(indegree[i]==1) {
                q.push(i);
                indegree[i]--;
            }
        } 
        
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++){
                int curr = q.front(); 
                q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr]){ 
                    indegree[child]--;
                    if(indegree[child]==1) 
                        q.push(child);   
                }
            }
        }
        if(n==1) 
            ans.push_back(0); 
        return ans;
        
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n=6;
    vector<vector<int>> edges={{3,0},{3,1},{3,2},{3,4},{5,4}};
    vector<int> ans = sol.findMinHeightTrees(n,edges);
    print(ans);
   return 0;
}