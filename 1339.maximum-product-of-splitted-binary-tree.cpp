/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
class Solution {  //t-> O(n) s-> O(h)
public:
    long long ans =0;
    long long totSum=0;
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        totSum = dfs(root);
        dfs(root);
        return ans%int(1e9+7);
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int curSum= dfs(root->left) + dfs(root->right)+ root->val;
        ans= max(ans, curSum * (totSum - curSum)); // the actual ans
        return curSum; // thr root will return this to it parent
    }
};
// @lc code=end


int main(){

    return 0;
}