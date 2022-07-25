/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
// #include "LinkedList.h"

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
    TreeNode* trimBST(TreeNode* root, int low, int high){
        if(!root) return root;
        if(root->val>=low && root->val<=high){
            root->left=trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
            return root;
        }
        if(root->val < low) 
            return trimBST(root->right,low,high);
        return trimBST(root->left,low,high);
    }
};

//  t->O(N)
//  s->O(N)
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) 
            return NULL;
        // if val greater than high that means all the node to the right of root will also be greater than high
        // so go left 
        if(root->val> high)
            return trimBST(root->left, low, high);
        // if val is small than low then all the values ont he left side of root will also be smaller 
        // so move right
        if(root->val<low)
            return trimBST(root->right, low, high);
        // those roots which ful full the condition 
        root->left= trimBST(root->left,low,high);
        root->right= trimBST(root->right, low, high);
        return root;
    }
};

// @lc code=end


int main(){
    Solution sol;
    TreeNode * root
    return 0;
}