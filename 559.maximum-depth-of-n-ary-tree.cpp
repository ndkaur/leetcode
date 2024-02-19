/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0 ;
        int depth =0;
        for(auto &child : root->children){
            depth = max(depth ,maxDepth(child));
        }
        return 1+depth;
    }
};

class Solution1 {
    public:
    int maxDepth(Node *root){
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        int depth =0;

        while(q.size()){
            depth++;
            int len =q.size();
            for(int i=0;i<len ;i++){
                Node *curr= q.front();
                q.pop();
                for(auto &child:curr->children){
                    if(child)
                        q.push(child);
                }
            }
        }
        return depth;
    }
};

class Solution1 {
    public:
    int maxDepth(Node *root){
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        int depth =0;
        while(!q.empty()){
            ++depth;
            queue<Node*> nq;
            while(!q.empty()){
                Node *curr= q.front();
                q.pop();
                for(auto &child:curr->children){
                    if(child)
                        nq.push(child);
                }
            }
            q = nq;
        }
    }
};

// level order traversal 
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int depth =0;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int sz= q.size();
            depth++;
            for(int i=0; i<sz; i++){
                root = q.front();
                q.pop();
                int n = root->children.size();
                for(int j=0; j<n; j++){
                    if(root->children[j])
                        q.push(root->children[j]);
                }
            }
        }
        return depth;
    }
};
// @lc code=end


int main(){
    Solution sol;
    return 0;
}