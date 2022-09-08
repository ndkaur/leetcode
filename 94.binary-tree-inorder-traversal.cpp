/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

//  inorder :-  left root right 
//  recursive
// O(n)  O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(!root) return;
        inorder(root->left);
        ans.push_back(node->val);
        inorder(root->right);
    }
};

//  iterative 
//O(n) O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st; 
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            root= st.top();
            st.pop();
            ans.push_back(root->val);
            root= root->right;
        }
        return ans;
    }
};


// moris traversal
//O(n)  O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        // left root right
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev= curr->left;
                while(prev->right!=NULL){
                    prev= prev->right;
                }
                prev->right = curr;
                TreeNode* temp = curr;
                curr= curr->left;
                temp->left = NULL; 
            }
        }
        return ans;
    }
};

// striver moris traversal 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        // left root right
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            // if curr left not exist 
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr= curr->right;
            }
            // if curr left exist 
            else{
                // we have to move one left and extreme right 
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev = prev->right;
                }
                // prev is at extreme right
                // prev->right  is null then make a connection
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left; 
                }
                // prev->right != null then break a connection 
                else{
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}