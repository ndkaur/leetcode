/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        
        if(root->left != NULL && root->left->val != root->val) return false;
        if(root->right != NULL && root->right->val != root->val) return false;
        
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
}; 

class Solution {
public:
    set<int>s;
    void fun(TreeNode* root){
        if(root == NULL){
            return;
        }
        s.insert(root->val);
        fun(root->left);
        fun(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        fun(root);
        if (s.size() == 1){
            return true;
        }
        else{
            return false;
        }
    }
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return dfs(root, root->val);
    }
    bool dfs(TreeNode* root, int x){
        if(!root) return true;
        if(root->val!=x)
            return false;
        return dfs(root->left, x) && dfs(root->right,x);
    }
};
// @lc code=end


int main(){

    return 0;
}