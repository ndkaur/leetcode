/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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

// question reduces to check if two different trees are equal to each other or not 
class Solution { // O(n^2)
public:
    bool isSubtree(TreeNode* root, TreeNode* subr) {
        if(!root) return false;
        if(isSame(root, subr))
            return true;
        return isSubtree(root->left, subr) || isSubtree(root->right, subr);
    }
    bool isSame(TreeNode* root, TreeNode* subr){
        if(!root && ! subr)
            return true;
        if(!root || !subr)
            return false;
        if(root->val != subr->val)
            return false;
        return isSame(root->left, subr->left) && isSame(root->right , subr->right);
    }
};


class Solution {
public:
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1  || !root2){
            return false;
        }
        if(root1->val != root2->val) return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        return (isSame(root,subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};

// @lc code=end


int main(){

    return 0;
}