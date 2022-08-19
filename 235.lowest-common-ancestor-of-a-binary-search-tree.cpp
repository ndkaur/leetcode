/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

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

//t->O(H)  sc->O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* curr= root;
        while(true){
            if(p->val<curr->val && q->val<curr->val)
                curr=curr->left;
            else if(p->val> curr->val && q->val> curr->val)
                curr= curr->right;
            else 
                break;
        }
        return curr;
    }
};


// can use the same code of lca of simple binary tree 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p==root || q==root)
            return root;
        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);
        if(!left)
            return right;
        else if(!right)
            return left;
        else
            return root;
    }
};



// @lc code=end



int main(){

    return 0;
}