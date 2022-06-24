/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,1);
        return ans;  
    }
    void dfs(TreeNode* root, vector<int> &ans, int level){
        if(!root) return ;
        if(ans.size()<level) 
            ans.push_back(root->val);
        dfs(root->right,ans,level+1);
        dfs(root->left,ans,level+1);
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,0,ans);
        return ans;  
    }
    //  root right left 
    void dfs(TreeNode* root, int level, vector<int>& ans){
        if(!root) return ;
        if(ans.size()==level)
            ans.push_back(root->val);
        dfs(root->right, level+1, ans);
        dfs(root->left, level+1,ans);
        
    }
};
// @lc code=end


int main(){
   
    return 0;
}