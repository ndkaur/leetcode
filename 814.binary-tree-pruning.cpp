/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
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

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
         return dfs(root) ? root :NULL;
    }
    bool dfs(TreeNode* root){
        if(!root) return false;
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        // if no one only zero then 
        if(!l) // l =0
            root->left= NULL;
        if(!r)
            root->right = NULL;
        // node= 1 or left or right tree has 1
        return root->val==1 || l || r;
    }
};


class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // if the val 0 has root has left or right cild then cant prune it 
        if(root->val==0 && (!root->left && !root->right))
            root= NULL;
        return root;
    }
};

int main(){

    return 0;
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// @lc code=end

