/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include "LinkedList.h"

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        // adding root to temp as every path will start from root
        string temp= to_string(root->val);
        dfs(root,temp,ans);
        return ans;
    }
    void dfs(TreeNode* root, string temp, vector<string>& ans){
        if(!root->left && !root->right){
            if(temp.size())
                ans.push_back(temp);
        }
        if(root->left)
            dfs(root->left, temp+ "->" + to_string(root->left->val) ,ans);
        if(root->right)
            dfs(root->right, temp + "->" + to_string(root->right->val), ans);
    }
};

// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}