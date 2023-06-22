/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    } 
    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2 )
            return false;
        if(root1->val!=root2->val)
            return false;
        // values can be from left left side or right right side 
        // no flip needed 
        bool left = dfs(root1->left , root2->left) && dfs(root1->right,root2->right);
        // or flip of values can be left right side 
        // flip needed 
        bool right = dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
        return left || right;
    }
};
// @lc code=end


int main(){

    return 0;
}