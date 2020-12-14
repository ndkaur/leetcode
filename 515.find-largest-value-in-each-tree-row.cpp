/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
// preorder : first root , left, right 
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        largest(root,ans,0);
        return ans;
    }
    void largest(TreeNode* root,vector<int>& ans, int level){
        if(!root)
            return ;
        if(level >= ans.size())
            ans.push_back(root->val);
        else 
            ans[level]=max(ans[level],root->val);
        largest(root->left,ans,level+1);                          
        largest(root->right,ans,level+1);
    }
};


// @lc code=end


int main(){
    
    return 0;
}