/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || p==root || q==root) // if already found the desired node dont go further
            return root;
        TreeNode* left= lowestCommonAncestor(root->left, p,q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);
        //  check what each recursive call is returning 
        if(left==NULL){ // if left node doesnot have child so the parent will give the result of the right side 
            return right;
        }
        else if(right== NULL){
            return left;
        }
        else{ // not left or right are not null so that means we have reached the actual ancestor
            return root;
        }
    }
};
// @lc code=end


int main(){

    return 0;
}