/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
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

// using simple bfs  
class Solution { 
public:
    void bfs(int src, int n, vector<vector<int>>& adj, vector<vector<bool>>& check){
        queue<int> q;
        q.push(src);

        while(q.size()){
            auto node = q.front();
            q.pop();
            // src->node->itr  
            // so the src->itr , src becomes the indirect parent of itr and create that edge
            for(auto itr:adj[node]){
                if(!check[src][itr]){
                    check[src][itr]=true;
                    q.push(itr);
                }
            }
        } 
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        vector<vector<int>> adj(n);
        for(auto p:pre){
            adj[p[0]].push_back(p[1]);
        }
        vector<bool> ans;
        vector<vector<bool>> check(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            bfs(i, n, adj, check);
        }

        // now check query 
        for(int i=0; i<qu.size(); i++){
            if(check[qu[i][0]][qu[i][1]])
                ans.push_back(true);
        }
        return ans;
    }
};



class Solution { // khans algo
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        vector<vector<int>> adj(num);
        vector<bool> ans;
        vector<int> indegree(num,0);
        vector<vector<bool>> check(num,vector<bool>(num,false));
        for(auto p:pre){
            int course= p[0];
            int depend= p[1];
            adj[course].push_back(depend);
            indegree[depend]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            for(auto it:adj[curr]){ // curr=1 , itr is its adj =0 , mark[1,0]as true 
                check[curr][it]= true;
                for(int i=0;i<num;i++){
                    if(check[i][curr]==true) // check[0][1]
                        check[i][it]= true; // check[0][0]
                }
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        } 
        // check if the querie is marked true in table bool 
        for(int i=0;i<qu.size();i++){
            ans.push_back(check[qu[i][0]][qu[i][1]]);
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int num=2;
    vector<vector<int>> pre={{1,0}};
    vector<vector<int>> qu={{0,1},{1,0}};
    vector<bool> ans = sol.checkIfPrerequisite(num,pre,qu);
    for(auto i:ans){
        cout<<i<<endl;
    }
   return 0;
}