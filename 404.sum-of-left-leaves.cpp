/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool isLeft){
        if(!root) return 0;
        if(!root->left && !root->right) 
            return isLeft ? root->val : 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum =0;
        dfs(root, sum, false);
        return sum;
    }
    void dfs(TreeNode* root, int& sum, bool isLeft){
        if(!root)
            return ;
        if(!root->left && !root->right)
            sum += isLeft? root->val:0;
        dfs(root->left, sum, true);
        dfs(root->right, sum, false);
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        while(!s.empty()){
            auto p= s.top();
            s.pop();
            TreeNode* curr= p.first;
            bool isLeft = p.second;
            // leaf node 
            if(!curr->left && !curr->right && isLeft)
                ans+= curr->val;
            if(curr->right) 
                s.push({curr->right, false});
            if(curr->left)
                s.push({curr->left, true});
        }
        return ans;
    }
};


// @lc code=end


int main(){

    return 0;
}