/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
class Solution { // tc->O(height) sc-> O(1)
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        // root val equal to key 
        if(root->val== key){
            return helper(root);
        }
        //  as we are changing the root val so its better to store the root first 
        TreeNode* dummy= root;
        while(root!=NULL){
            // check on left side
            if(root->val>key){
            // root->left = key
                if(root->left!=NULL && root->left->val==key){
                    root->left= helper(root->left);
                    break;
                }
                else{
                    root= root->left;
                }
            } 
            else{ // check on right side
                if(root->right!=NULL && root->right->val==key){
                    root->right= helper(root->right);
                    break;
                }
                else 
                    root = root->right;
            }
        }
        return dummy;
    }
    //  we are removing the right side link 
    //  edge case -> if we remove right link but the left child doenot exist 
    TreeNode* helper(TreeNode* root){
        //  edge case 
        if(root->left==NULL) 
            return root->right;
        else if(root->right==NULL)
            return root->left;
        TreeNode* rchild= root->right;
        TreeNode* lastRight= findLastRight(root->left);
        lastRight->right= rchild;
        return root->left; // we have atatched the right broken subtree with the last right of the left subtree
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right==NULL)
            return root;
        // if right child exists then keep in moving to the last right possible 
        return findLastRight(root->right);
    }
};
// @lc code=end

