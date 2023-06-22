/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode *> ans;
    set<int> seen;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto d:to_delete)
            seen.insert(d);
        root= dfs(root,0);
        return ans;
    }
    TreeNode* dfs(TreeNode * root , bool has_seen){
        if(!root) return root;
        bool notwatch = !seen.count(root->val);
        // that numbers are not coming in to delete array
        root->left =dfs(root->left,notwatch);
        root->right =dfs(root->right,notwatch);
        if(!has_seen && notwatch)
            ans.push_back(root);                     
        if(!notwatch) 
            return NULL;
        return root;
    }
}; 


class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        vector<TreeNode*> ans;
        set<int> s;
        for(int d:to_delete)
            s.insert(d);
        TreeNode* node = dfs(root,ans, s);
        if(node)
            ans.push_back(node);
        return ans;
    }
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& ans, set<int>& s){
        if(!root) NULL;
        if(root->left)
            root->left = dfs(root->left, ans, s);
        if(root->right)
            root->right = dfs(root->right, ans, s);
        if(s.count(root->val)){
            if(root->left) 
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
};

// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}