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

//dfs
class Solution0 {
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

// bfs
class Solution1 {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        int n= graph.size()-1;
        q.push({0});
        while(!q.empty()){
            auto vertex= q.front(); // array
            q.pop();
            if(vertex.back()==n){
                ans.push_back(vertex);
            }else{
                auto nextVertex = graph[vertex.back()];
                for(int i=0;i<nextVertex.size();i++){
                    vector<int> temp(vertex.begin(),vertex.end());
                    temp.push_back(nextVertex[i]);
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};

//bfs
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size()-1;
        vector<int> path;
        path.push_back(0);
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push(path);
        while(!q.empty()){
            path = q.front();
            q.pop();
            int val=path.back();
            if(val==n){
                ans.push_back(path); // reached destination
            }
            for(int it:graph[val]){
                vector<int> v(path);
                v.push_back(it);
                q.push(v);
            }
        }
        return ans;
    }
};

//  easy bfs 
// queue formed will be  
// {0} ,{0,1},{0,2},{0,1,3},{0,2,3} 

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n= graph.size();
        //  graph is stored in form of vi so the ans required is also in form of vi
        vector<vector<int>> ans;
        vector<int> path;
        //  q in from of vi that store the path value till that point 
        queue<vector<int>> q;

        q.push({0});
        while(!q.empty()){
            path= q.front(); // in form of vi 
            q.pop();
            //  if last elemt of vector<int> path is equal to n-1 ie destination 
            if(path.back()==n-1)
                ans.push_back(path); // one path found
            else {
                for(auto itr: graph[path.back()]){  // start itr from the last visited node ie the vector<int> path's last val
                    vector<int> v = path; // in order to add new itr we made a new vi v= path 
                    v.push_back(itr);
                    q.push(v);
                }
            }
        }
        return ans;
    }
};

// @lc code=end

int main(){
    Solution sol;
    vector<vector<int>> graph={{1,3},{2},{3},{}};
    vector<vector<int>> result =sol.allPathsSourceTarget(graph);
    for(auto x:result){
        print(x);
    }
    return 0;
}