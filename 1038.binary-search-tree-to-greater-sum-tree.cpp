/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
 */

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
    int total=0; // in fuction resursion so every time total val starts from 0
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        if(root->right)
            bstToGst(root->right);
        root->val = root->val+total;
        total = root->val;
        if(root->left)
            bstToGst(root->left);
        return root;
    }
};


class Solution0 {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        int total=0;
        dfs(root,total);
        return root;
    }
    // pass val by reference as we take the previous cal val and changing it again n again 
    void dfs(TreeNode* root, int &total){
        if(!root) return;
        dfs(root->right,total);
        root->val = root->val+total;
        total= root->val;
        dfs(root->left, total);
    }
};


class Solution {
public:
    void find(TreeNode* root, int& sum){
        if(!root)
            return;
        find(root->right, sum);
        sum += root->val;
        root->val = sum;
        find(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        find(root, sum);
        return root;
    }
};
// @lc code=end

