/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int,int> m; // map on postorder
        for(int i=0;i<postorder.size();i++){
            m[postorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1, m);
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,  vector<int>& postorder, int postStart, int postEnd, map<int,int>& m ){
        TreeNode* root= new TreeNode(preorder[preStart]);
        if(preStart== preEnd) 
            return root;
        int postRoot= m[preorder[preStart+1]];// the index of the root where left child of main root is present
        int numLeft= postRoot-postStart+1;// index in post where all nodes before it are left side nodes

        root->left= build(preorder, preStart+1, preStart+numLeft, postorder, postStart, postStart+numLeft-1, m);
        if(postRoot+1== postEnd) // if right child subtree of tree is empty 
            return root;
            //  consider everything index wise 
        root->right = build(preorder, preStart+numLeft+1, preEnd , postorder, postRoot+1, postEnd-1,m);
        return root;
    }
};

//  find the actual value of required node of preorder, see its index and the calculate its index with respect to postorder marked values postroot and numleft
// @lc code=end

