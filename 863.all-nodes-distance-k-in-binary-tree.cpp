/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    // child ->parent 
    map<TreeNode*,TreeNode*> parent; // to save the value of parent and its child
    set<TreeNode*> visit; // to mark the visit or not 

    // ditance k can be left right or in upward direction ie from root to its parent 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        find_parent(root);
        distance_ans(target,k); // have to find the values of roots from the target at k distance 
        return ans;
    }

    void distance_ans(TreeNode* root, int k){
        if(visit.find(root) != visit.end())
            return;
        visit.insert(root);
        if(k==0){ // at the same location 
            ans.push_back(root->val); // insert the current root 
            return;
        }
        if(root->left)
            distance_ans(root->left,k-1);
        if(root->right)
            distance_ans(root->right,k-1);
        // if parent exisit then we can move upward till k 
        TreeNode* p = parent[root];
        if(p) 
            distance_ans(p,k-1);
    }

    void find_parent(TreeNode* root){
        // filling the map of child ->parent values
        if(!root) return;
        if(root->left) {
            parent[root->left] = root; // saved value of root in place of root->left
            find_parent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            find_parent(root->right);
        }
    }
};

// bfs  ->O(n) + O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        // map to store parent for each children so that we can move upward at k distance too
        map<TreeNode* , TreeNode*> mp; // child parent 
        findParentmp(root, mp);
        // visited
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr =0;
        while(!q.empty()){
            int sz = q.size();
            if(curr == k)
                break;
            curr++;
            for(int i=0; i<sz; i++){
                TreeNode* node= q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(mp[node] && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* f= q.front();
            q.pop();
            ans.push_back(f->val);
        }
        return ans;
    }
    
    void findParentmp(TreeNode* root, map<TreeNode*, TreeNode*>& mp){
        if(!root)
            return;
        if(root->left){
            mp[root->left] = root;
            findParentmp(root->left, mp);
        }    
        if(root->right){
            mp[root->right] = root;
            findParentmp(root->right, mp);
        }
    }
    
};


// @lc code=end


int main(){

    return 0;
}