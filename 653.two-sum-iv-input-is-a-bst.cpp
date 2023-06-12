/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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

// tc-> O(n)  sc->O(n)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> ans;
        dfs(root, k, ans);
        int n= ans.size();
        for(int i=0,j=n-1; i<j;){
            if(ans[i]+ans[j]==k) return true;
            ans[i]+ans[j]<k ? i++ : j--;
        }
        return false;
    }
    void dfs(TreeNode* root, int k, vector<int>& ans){
        if(!root) return;
        dfs(root->left,k,ans);
        ans.push_back(root->val);
        dfs(root->right,k, ans);
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root,s,k);
    }
    bool dfs(TreeNode* root, unordered_set<int>& s, int k){
        if(!root) return false;
        if(s.count(k - root->val))
            return true;
        s.insert(root->val);
        return dfs(root->left, k) || dfs(root->right, k);
    }
};

// @lc code=end


int main(){

    return 0;
}