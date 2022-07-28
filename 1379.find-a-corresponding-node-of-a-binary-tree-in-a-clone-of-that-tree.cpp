/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// take 2 stacks one for original, one for clone so iterate both and check if original equal to target 
// if equal then return clone value 
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        TreeNode* oroot= original;
        TreeNode* croot= cloned;
        while(oroot || !st1.empty()){
            while(oroot){
                st1.push(oroot);
                st2.push(croot);
                oroot= oroot->left;
                croot= croot->left;
            }
            oroot= st1.top();
            st1.pop();
            croot= st2.top();
            st2.pop();
            if(oroot == target){
                return croot;
            }
            oroot = oroot->right;
            croot= croot->right;
        }
        return NULL;
    }
};



class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = NULL;
        dfs(original, cloned, target , ans);
        return ans;
    }
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &ans){
        if(!original)
            return;
        if(original==target)
            ans = cloned;
        dfs(original->left, cloned->left, target, ans);
        dfs(original->right, cloned->right, target, ans);
    }
};


// @lc code=end


int main(){

    return 0;
}