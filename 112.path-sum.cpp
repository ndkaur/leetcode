/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum=sum-root->val;
        if(sum==0 && !root->left && !root->right) return true;
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        stack<pair<TreeNode *,int>> stk;
        stk.push({root,root->val});
        while(!stk.empty()){
            TreeNode *curr =stk.top().first;
            int tsum= stk.top().second;
            stk.pop();
            if(curr->left) stk.push({curr->left,tsum+curr->left->val});
            if(curr->right) stk.push({curr->right, tsum+curr->right->val});
            if(!curr->left && !curr->right && tsum==sum)
                return true;

        }
        return false;
    }
};
// @lc code=end

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    string s = "[]"; int sum =0;
    TreeNode* root = stringToTreeNode(s);
    bool out = sol.hasPathSum(root, sum); deb(out);
    return 0;
}
