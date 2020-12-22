/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
// recursive
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isbst(root,LONG_MIN,LONG_MAX);
    }
    bool isbst(TreeNode* root,long min,long max){
        if(!root) return true;
        bool left= isbst(root->left,min,root->val);
        bool right=isbst(root->right,root->val,max);
        // root->val wrt left side it must be root->val>left(min)
        // root->val wrt right side it must be root->val<right(max)
        return(left && right && root->val>min && root->val<max );
    }
};

//inorder : left ,root, right
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        stack<TreeNode*>s;
        TreeNode* curr=root;
        long max = LONG_MIN;
        while(!s.empty() || curr){
            while(curr){
                s.push(curr); 
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            if(curr->val<=max) // left is greater than root 
                return false;
            max=curr->val; 
            curr=curr->right;
        }
        return true;
    }
};

// @lc code=end


int main(){
    
    return 0;
}