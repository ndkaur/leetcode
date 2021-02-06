/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    int prev=-1;
     int ans=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return 0;
       // left root right
        if(root->left) 
            minDiffInBST(root->left);
        if(prev>=0) {
            int curans= root->val-prev;
            ans= min(ans,curans);
        }
        prev=root->val;
        if(root->right)
            minDiffInBST(root->right);
        return ans;
    }
};
// @lc code=end

int main(){
    
    return 0;
}