/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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

class Solution0 {
public:
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        int val=0;
        if(root->left!=NULL) 
            val += rob(root->left->left)+ rob(root->left->right);
        if(root->right!=NULL)
            val += rob(root->right->left) + rob(root->right->right);
        return max(root->val+val , rob(root->left) +rob(root->right));
    }
}; // time limit exceeded 

const int robbed=1;
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> node = help(root);
        return max(node[robbed],node[!robbed]);
    }
    vector<int> help(TreeNode* root){
        if(!root) return {0,0};
        vector<int> left= help(root->left);
        vector<int> right = help(root->right);
        vector<int> node ={0,0};
        // if parent is robbed then child cannot be robbed
        node[robbed] = root->val + left[!robbed] + right[!robbed]; 
        // if parent is not robbed then child can and canot be robbed
        node[!robbed] = max(left[robbed], left[!robbed])+ max(right[robbed],right[!robbed]);
        return node;
    }
};


//  2 options , with or without robberry 
    //  a                  -> p with   , q->without
//   b     c  
// with robery at a->    left.q + right.q + root->val
//  without robbery at a -> can rob next level -> max(left.with , left. without ) + max(right. with , right.without)
 


class Solution0 { //tle O(2^N)
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        return f(root, 1);
    }
    int f(TreeNode* root, int pick){
        if(!root)
            return 0;
        int npickval = f(root->left,1) + f(root->right,1);
        int pickval = pick==1 ? root->val + f(root->left, 0) + f(root->right,0) : -1;
        return max(pickval, npickval);
    }
};


class Solution1 { //tle O(2^N)
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int npick = rob(root->left) + rob(root->right);
        int pick = root->val;
        if(root->left)
            pick += rob(root->left->left) + rob(root->left->right);
        if(root->right) 
            pick += rob(root->right->left) + rob(root->right->right);
        return max(pick, npick);
    }
};


// to avoid tle we need to store the precalculated answer to the node 
// so we can use a map of node , int

class Solution {  //O(N)
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if(dp.count(root)) // that root already store in map then return it directly
            return dp[root];
        int npick = rob(root->left) + rob(root->right);
        
        int pick = root->val;
        
        if(root->left)
            pick += rob(root->left->left) + rob(root->left->right);
        if(root->right) 
            pick += rob(root->right->left) + rob(root->right->right);
        
        return dp[root] = max(pick, npick);
    }
};
 
// @lc code=end


int main(){
    Solution sol;
    vs trees = {"[3,2,3,null,3,null,1]",
        "[3,4,5,1,3,null,1]",
    };
    for(auto s: trees){
        TreeNode* root = stringToTreeNode(s);
        int out = sol.rob(root);
        cout<<out;
    }
    return 0;
}