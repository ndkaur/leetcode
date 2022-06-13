/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool ans;
public:
    bool isBalanced(TreeNode* root) {
        ans =true;
        int temp=check(root);
        return ans;
    }
    int check(TreeNode *root ){
        if(!root)
            return 0;
        if(!ans) return 0;
        int lefttree = check(root->left);
        int righttree = check(root->right);
        if(abs(lefttree-righttree)>1)
            ans = false;
        return 1+max(lefttree,righttree);
    }
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l= height(root->left);
        if(l==-1) return -1;
        int r = height(root->right);
        if(r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return max(l,r)+1;
    }
};

// @lc code=end

int main(){
    
    return 0;
}