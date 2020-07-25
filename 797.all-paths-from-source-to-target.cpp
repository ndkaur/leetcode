/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
    void dfs(vector<vector<int>> &graph,vector<vector<int>> &result,vector<int> path,int vertex){
        path.push_back(vertex);
        if(vertex==graph.size()-1)
            result.push_back(path);
        else 
            for(int v:graph[vertex]){
                dfs(graph,result,path,v);
            }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph,result,path,0);
        return result;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>> graph={{1,2},{3},{3},{}};
    vector<vector<int>> result =sol.allPathsSourceTarget(graph);
    for(auto x:result){
        print(x);
    }
    return 0;
}