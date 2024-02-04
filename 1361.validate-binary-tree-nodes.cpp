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
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        // no node should have indeg more than 1 , and no cycle 
        // any tree has n-1 edges 
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        int edges = 0;

        for(int i=0; i<n; i++){
            if(left[i]!=-1){
                indeg[left[i]]++;
                edges++;
                adj[i].push_back(left[i]);
            }
            if(right[i]!=-1){
                indeg[right[i]]++;
                edges++;
                adj[i].push_back(right[i]);
            }
        }

        if(edges!=n-1)
            return false;
        
        vector<int> visited(n,0);
        queue<int> q;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(indeg[i]>1)
                return false;
            if(indeg[i]==0){
                q.push(i);
                cnt++;
            }
        }

        while(q.size()){
            auto node = q.front();
            q.pop();
            visited[node]=1;
            for(auto itr:adj[node]){
                indeg[itr]--;
                if(!visited[itr] && indeg[itr]==0){
                    q.push(itr);
                    cnt++;
                }
            }
        }

        if(cnt!=n){ // cycle
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n,0);
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
            // parent-> child relation 
                adj[i].push_back(leftChild[i]);
                in[leftChild[i]]++;
            }
            if(rightChild[i]!=-1){
                adj[i].push_back(rightChild[i]);
                in[rightChild[i]]++;
            }
            // if any parent has more than 2 children or its indegree is more than 2 
            if(adj[i].size()>2 || in[i]>2) return false;
        }
        
        queue<int> q;
        int count=0;
        for(int i=0;i<in.size();i++){
            if(in[i]==0)
                q.push(i);
        }
        // only one root node will exist and only the root node will have the indegree as 0 
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


//  valid bt -> 1st condition -> if each node gets visited only ones 
//  2nd condition->  if a single tree is formed ie only one node wihtout parent
// left= {1,-1,3,1}  0 left=1 ,  1 left= -1 ,  2 left= 3  , 1 left=1

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n,0);
        queue<int> q;
        q.push(0);
        //  checking each node visited ones
        while(!q.empty()){
            int top= q.front();
            q.pop();
            if(visited[top]) // if node already visited then node not a valid tree form 
                return false;
            visited[top]= true;
            if(leftChild[top]!=-1)
                q.push(leftChild[top]);
            if(rightChild[top]!=-1)
                q.push(rightChild[top]);
        }
        //  check number of nodes without parent ie if a single or multiple tree formed
        vector<int> without_parent(n,1);
        for(int i:leftChild){
            if(i!=-1) 
                without_parent[i]=0;
        }
        for(int i:rightChild){
            if(i!=-1)
                without_parent[i]=0;
        }
        int tot = accumulate(without_parent.begin(), without_parent.end(),0);
        return (tot==1)? true:false;
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