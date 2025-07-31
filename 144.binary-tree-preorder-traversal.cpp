/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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

// Preorder -> root left right   

//  recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root,ans);
        return ans;
    }
    void preOrder(TreeNode* root, vector<int>& ans){
        if(!root) return;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right, ans);
    }
};

//  iterative 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp= st.top();
            ans.push_back(temp->val);
            st.pop();
            //  stack right push then left push 
            if(temp->right) 
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ans;
    }
};


// morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // pre = root left right 
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode* prev = root->left;
                while(prev->right && prev->right!=root){
                    prev = prev->right;
                }
                if(!prev->right){ // null
                    prev->right = root;
                    ans.push_back(root->val);
                    root = root->left;
                }
                else{ // already connected to the root 
                    prev->right = NULL;
                    root = root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root= root->right;
            }
        }
        return ans;
    }
};




// @lc code=end


int main(){

    return 0;
}