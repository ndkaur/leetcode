/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
    int depth;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth =findDepth(root);
        root= deepSubtree(root,1);
        return root;
    }

    TreeNode* deepSubtree(TreeNode* root, int d){
        if(!root) 
            return NULL;
        if(d==depth) 
            return root;
        TreeNode* left= deepSubtree(root->left, d+1);
        TreeNode* right= deepSubtree(root->right, d+1);
        if(left && right) 
            return root;
        if(left || right)
            return left?left:right;
        return NULL;
    }

    int findDepth(TreeNode* root){
        if(!root) 
            return 0;
        int dep=max(findDepth(root->left), findDepth(root->right));
        return dep+1; 
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