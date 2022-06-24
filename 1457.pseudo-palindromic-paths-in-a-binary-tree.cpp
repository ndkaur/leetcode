/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
    int count=0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count;
    }
    void preorder(TreeNode *root, int times){
        if(root != NULL){
            //no of occurence 
            times = times ^ (1<<root->val);
            // if pseudo or not 
            if(root->left ==NULL && root->right == NULL){
                // frequency as 1 of at most one digit 
                if(times & (times-1) ==0)
                    count++;
            }
            preorder(root->left , times);
            preorder(root->right,times);
        }
    }
};
// @lc code=end

