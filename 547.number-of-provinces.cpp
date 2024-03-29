/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
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

//DFS
class Solution0 {
public:
    int findCircleNum(vector<vector<int>>& grid){
        int n= grid.size();
        int count=0;
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(visited, grid,i);
            }
        }
        return count;
    }
    void dfs(vector<bool>& visited, vector<vector<int>>& grid, int i){
        visited[i]=1;
        for(int j=0;j<grid.size();j++){
            if(!visited[j] && grid[i][j]==1)
                dfs(visited, grid,j);
        }
    }
};

//BFS

class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid){
        int n= grid.size();
        int count=0;
        vector<bool> visited(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                q.push(i);
                while(!q.empty()){
                    auto curr= q.front();
                    q.pop();
                    visited[curr]=true;
                    for(int j=0;j<n;j++){
                        if(!visited[j] && grid[curr][j]==1){ 
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> visited(n,0);
        int cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                q.push(i);
                visited[i]= 1;
                while(!q.empty()){
                    auto node= q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(!visited[j] && isConnected[node][j]==1){
                            q.push(j);
                            visited[j]=1;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


// union find  ->O(N)
class Solution {
public:
    vector<int> parent;

    int findParent(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionn(int u, int v){
        u = findParent(u);
        v = findParent(v);
        parent[u] = v;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int  n = isConnected.size();
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int cnt =n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    int pari = findParent(i);
                    int parj = findParent(j);
                    if(pari != parj){
                        cnt--;
                        unionn(pari,parj);
                    }
                }
            }
        }
        return cnt;
    }

};

// @lc code=end


int main(){
    Solution sol;
    vector<vector<int>> grid ={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    int ans =sol.findCircleNum(grid);
    cout<<ans;
   return 0;
}