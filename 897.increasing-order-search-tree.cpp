/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *curr;
        TreeNode *out = new TreeNode(-1);
        curr = out;
        dfs(out,root);
        return curr->right;
    }
    // left  root right        
    void dfs(TreeNode* &out, TreeNode *root){
        if(!root) return ;
        dfs(out,root->left);
        out->right = new TreeNode(root->val);
        out= out->right;
        dfs(out,root->right);
    }
};

// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    string s;
    TreeNode* root;
    s = "[5,3,6,2,4,null,8,1,null,null,null,7,9]";
    root = stringToTreeNode(s);
    root = sol.increasingBST(root);
    s = treeNodeToString(root); 
    deb(s);
    return 0;
    return 0;
}