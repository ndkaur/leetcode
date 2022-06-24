/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> m; // store count of each string , 2 4 = 2times 
        solve(root,m,ans);
        return ans;
    }
    string solve(TreeNode* root, unordered_map<string,int>& m, vector<TreeNode*> &ans){
        if(!root)
            return "";
        string left= solve(root->left,m , ans);
        string right= solve(root->right, m , ans);
        string s= to_string(root->val) + ","+ left+","+ right;
        if(m[s]==1) // current string already present in the map ie this current string formed is a duplicate 
            ans.push_back(root);
        mp[s]++;
        return s;
    }
};
// @lc code=end


int main(){

    return 0;
}