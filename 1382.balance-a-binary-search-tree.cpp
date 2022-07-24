/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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


//  same as generate a binary tree from array 
class Solution {
public:
    vector<int> ans;
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return atree(0,ans.size()-1);
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    // l and r not passed with reference as their value will ot change the whole time 
    TreeNode* atree(int l, int r){
        if(l>r) return NULL;
        int mid= l+(r-l)/2;
        TreeNode* root= new TreeNode(ans[mid]);
        root->left= atree(l,mid-1);
        root->right= atree(mid+1,r);
        return root;
    }
};

// @lc code=end


int main(){

    return 0;
}