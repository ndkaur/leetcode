/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr= st.top();
            st.pop();
            if(!curr) continue;
            st.push(curr->left);
            st.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right)
                q.push(curr->right);
            TreeNode* temp= curr->left;
            curr->left= curr->right;
            curr->right= temp;
        }
        return root;
    }
};

// @lc code=end



int main(){

    return 0;
}