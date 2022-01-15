/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
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
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n,0);
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                adj[i].push_back(leftChild[i]);
                in[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                in[rightChild[i]]++;
            }
            if(adj[i].size()>2 || in[i]>2) return false;
        }
        queue<int> q;
        int count=0;
        for(int i=0;i<in.size();i++){
            if(in[i]==0)
                q.push(i);
        }
        if(q.size()!=1) return false; // if already 2 node with in =0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            if(visited[node]==1) return false;
            visited[node]=1;
            count++;
            for(auto x:adj[node]){
                q.push(x);
            }
        }
        return count!=n? false:true;
    }
};
// @lc code=end

// testcase on which simple bfs doesnot work 
// n=6;
// left= {1,-1,-1,4,-1,-1};
// right={2,-1,-1,5,-1,-1};  
// 3 child are 4 and 5 which are disconnected

int main(){
    Solution sol;
    int n=2;
    vector<int> left={1,0};
    vector<int> right ={-1,-1};
    bool ans = sol.validateBinaryTreeNodes(n,left,right);
    cout<<ans;
    return 0;
}