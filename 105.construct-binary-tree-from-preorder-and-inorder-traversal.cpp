/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

// inorder->   40 20 *50 [10] 60 30 
// preorder->  [10] 20 40 *50 30 60 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //  a map to store idx of each node of inorder
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root= build(preorder, 0 , preorder.size()-1, inorder, 0,inorder.size()-1, inMap);
        return root;
    }
    TreeNode* build(vector<int>& preorder , int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& inMap){
        if(preStart> preEnd || inStart>inEnd) return NULL;
        //  first value of preorder array is the root 
        TreeNode* root = new TreeNode(preorder[preStart]);
        //  find the root in inorder 
        int inRoot= inMap[root->val]; // idx of root in inorder
        int numLeft =inRoot - inStart; // idx till which left side nums are present before root in preorder

        root->left = build(preorder, preStart+1, preStart + numLeft , inorder, inStart, inRoot-1 , inMap);
        root->right= build(preorder, preStart + numLeft+1, preEnd , inorder, inRoot+1, inEnd, inMap);

        return root;
    }
};
// @lc code=end


int main(){

    return 0;
}