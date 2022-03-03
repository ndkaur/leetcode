/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    vector<int> ans;
    void preorder(TreeNode* root){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        preorder(root);
        TreeNode* start= root;
        for(int i=1;i<ans.size();i++){
            start->left= NULL;
            TreeNode* temp= new TreeNode(ans[i]);
            start->right= temp;
            start= start->right;
        }
    }
};

class Solution { // recursive
public:
    TreeNode* prev= NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flaten(root->right);
        flaten(root->left);
        root->right= prev;
        root->left= NULL;
        prev= root;
    }
};
// @lc code=end


int main(){

    return 0;
}