/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
private :
    int sum=0;
public:
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(root->right)
            dfs(root->right);
        sum=sum+root->val;
        root->val=sum;
        if(root->left)
            dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) 
            return NULL;
        int val=0;
        dfs(root,val);
        return root;
    }
    void dfs(TreeNode* root, int &val){
        if(!root) return;
        dfs(root->right,val);
        root->val = root->val+val;
        val= root->val;
        dfs(root->left, val);
    }
};
// @lc code=end


int main(){
    
    return 0;
}