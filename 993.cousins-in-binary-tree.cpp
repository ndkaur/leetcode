/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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

// conditon is both x and y must not belong to same parent and depth must be equal
// so check depth as well as parent  
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xdep= -1;
        int ydep= -1;
        TreeNode* xpar= findDepth(root, x, 0, xdep);
        TreeNode* ypar= findDepth(root, y,0, ydep);

        if(xdep != ydep || xpar == ypar)
            return false;
        return true;
    }
    TreeNode* findDepth(TreeNode* root, int val, int depth, int& level){
        if(!root) return NULL;
        // when any of the root children is equal to the given x or y 
        if((root->left && root->left->val == val) || (root->right && root->right->val==val)){
            // update the level
            level= depth;
            // root is the parent node of x or y 
            return root;
        }
        // level is used to store the actual depth 

        TreeNode* left= findDepth(root->left, val, depth+1 , level);
        if(left) 
            return left;
        TreeNode* right = findDepth(root->right, val, depth+1, level);
        if(right) 
            return right;
        return NULL;
    }
};

// @lc code=end


int main(){

    return 0;
}