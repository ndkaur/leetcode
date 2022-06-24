/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
    int depth ;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth = findDepth(root); 
        return lca(root,1);
    }
    TreeNode * lca(TreeNode * root, int d){
        if(!root) return NULL;
        if(d==depth) // only one level of tree exists
            return root;
        TreeNode* l= lca(root->left,d+1); // d+1 because left is in next level
        TreeNode* r = lca(root->right, d+1);

        if(l && r) // it is deepest leaf // if both l and r exists 
            return root;
        if(l || r) // if one among l or r exist 
            return l ? l:r;
        return NULL;

    }

    int findDepth(TreeNode *root){
        if(!root) 
            return 0;
        int d= max(findDepth(root->left),findDepth(root->right));
        return 1+d;
    }
};


//  use same code of lca q no 236
class Solution {
public:
    int depth;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth = findDepth(root);
        return lca(root,1);
    }
    TreeNode* lca(TreeNode* root, int d){
        if(!root) return NULL;
        if(d==depth) 
            return root;
        TreeNode* left= lca(root->left,d+1);
        TreeNode* right = lca(root->right, d+1);
        if(left ==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
        
    }
    int findDepth(TreeNode* root){
        if(!root) return 0;
        int d= max(findDepth(root->left), findDepth(root->right));
        return d+1;
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