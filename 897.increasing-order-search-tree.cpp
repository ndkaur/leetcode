/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* newTree= new TreeNode(0);
        TreeNode* curr= newTree;
        dfs(curr,root);
        return newTree->right;
    }
    void dfs(TreeNode* &curr, TreeNode* root){
        if(root==NULL) return;
        dfs(curr, root->left);
        curr->right= new TreeNode(root->val);
        curr= curr->right;
        dfs(curr, root->right);
        
    }
};

class Solution {
public:
    void dfs(TreeNode* &curr , TreeNode* root){
        if(root==NULL) return;
        dfs(curr, root->left);
        root->left= NULL;
        curr->right= root;
        curr= curr->right;
        dfs(curr, root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* newtree= new TreeNode(0);
        TreeNode* curr= newtree;
        dfs(curr,root);
        return newtree->right;
    } 
}; 


class Solution {  //t->O(n)  s->O(n)
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        stack<TreeNode*> st;
        TreeNode* curr= root;
        TreeNode* newTree= new TreeNode(0);
        TreeNode* noder= newTree;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr= curr->left;
            }
            curr= st.top();
            st.pop();
            
            noder->right= curr;
            noder= noder->right;
            // first move node to right then make left as null
            noder->left=NULL;
           
            curr= curr->right;
        }
        return newTree->right;
    }
};


// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    string s;
    TreeNode* root;
    s = "[5,3,6,2,4,null,8,1,null,null,null,7,9]";
    root = stringToTreeNode(s);
    root = sol.increasingBST(root);
    s = treeNodeToString(root); 
    deb(s);
    return 0;
    return 0;
}