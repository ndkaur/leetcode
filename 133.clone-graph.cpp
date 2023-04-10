/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    Node* clone(unordered_map<int,Node*> &copy,Node* n){
        if(copy[n->val]) return copy[n->val]; // if copy of this node exist return it
        // create new copy 
        copy[n->val] = new Node(n->val);
        //create copy of neighbours 
        for(auto &x:n->neighbors){
            auto &neighbors_copy = copy[n->val]->neighbors;
            neighbors_copy.push_back(clone(copy,x));
        }
        // return copy of node
        return copy[n->val];
    }
public:
    Node* cloneGraph(Node* node) {
       if(!node) return node;
       unordered_map<int,Node*> copy;
       return clone(copy,node);
    }
};

// O(V + E) - for BFS
// Space: O(V) - for the hashmap
//dfs
class Solution {
public:
    unordered_map<Node*, Node*> mp; // node , cnt .. to check if node exist or not
    Node* cloneGraph(Node* node) {
       if(!node) return node;
       // check if node already exist in clone graph or not
       if(mp.find(node)==mp.end()){ // if copy of the required node doesnot exist 
            mp[node] = new Node(node->val,{}); // make a new node
            // adding its adjacent elements also in map
            for(auto adj:node->neighbors){ 
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }
       }
       return mp[node];
    }
};

//bfs
class Solution {
public:
    unordered_map<Node*, Node*> mp; // node , cnt .. to check if node exist or not
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        // creating the first node of graph 
        Node* first= new Node(node->val,{});
        mp[node]= first;

        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr= q.front();
            q.pop();
            // visiting the adjacents 
            for(auto adj: curr->neighbors){
                // if not visited check 
                if(mp.find(adj)== mp.end()){
                    mp[adj] = new Node(adj->val,{});
                    q.push(adj);
                }
                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
};


// @lc code=end


int main(){

    return 0;
}