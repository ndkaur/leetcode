/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout << x << endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
// #include "LinkedList.h"

void print(vi &out)
{
    for (auto x : out)
        cout << x << " ";
    cout << endl;
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



class Solution1 {
public:
    void f(TreeNode *root,int cur,int &sum){
        if(!root)
            return;
        cur = (cur*2)+root->val;
        if(!root->left and !root->right)
            sum+=cur;
        f(root->left,cur,sum);
        f(root->right,cur,sum);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int cur=0;
        int sum=0;
        f(root,cur,sum);
        return sum;
    }
};

class Solution0 {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);    
    }
    int  dfs(TreeNode* root, int num){
        if(!root) 
            return 0;
        num = (num<<1) | root->val;
        
        if(!root->left && !root->right){
            return num;
        }
        return dfs(root->left, num) + dfs(root->right, num);
    }
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        int sum =0;
        // node, curr num 
        stack<pair<TreeNode*, int>>stk;
        stk.push({root,0}); 

        while(stk.size()){
            auto node = stk.top();
            stk.pop();
            TreeNode* curr = node.first;
            int num = node.second;

            num = (num<<1) | curr->val;
            if(!curr->left && !curr->right){
                sum += num;
            }
            if(curr->left)
                stk.push({curr->left, num});
            if(curr->right)
                stk.push({curr->right, num});
        }
        return sum;
    }
};


// @lc code=end

int main()
{

    return 0;
}