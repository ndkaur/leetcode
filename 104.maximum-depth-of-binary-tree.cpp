/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int mxdepth = max(maxDepth(root->left), maxDepth(root->right));
        return 1+mxdepth;
    }
};

// using queue 
class Solution {
    public:
    int maxDepth(TreeNode *root){
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth =0;
        while(!q.empty()){
            depth++;
            int len =q.size();
            for(int i=0;i<len;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left !=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return depth;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l= maxDepth(root->left);
        int r= maxDepth(root->right);
        return max(l,r)+1;
    }
};

// @lc code=end



int main(){

    return 0;
}