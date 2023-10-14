/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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

// maximum difference  = abs (max val - min val)
// so keep treack of max val and min val;


class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        int mx = root->val;
        int mn = root->val;
        int ans =INT_MIN;
        dfs(mx, mn, ans, root);
        return ans;
    }
    void dfs(int mx, int mn, int& ans, TreeNode* root){
        if(!root)
            return;
            mx = max(mx, root->val);
            mn = min(mn, root->val);
            ans = max(ans, mx-mn);
        if(root->left){
            dfs(mx, mn, ans, root->left);
        }
        if(root->right){
            dfs(mx, mn, ans, root->right);
        }
    }
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, root->val, root->val);
    }
    int dfs(TreeNode* root, int mx, int mn){
        if(root == NULL) // reached the one end 
            return abs(mx-mn);
        // as we traverse we keep track of max and min val so that the abs 
        // difference becomes greater 
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        // maximum difference can come from any side right or left
        int left = dfs(root->left, mx, mn);
        int right = dfs(root->right, mx, mn);
        return max(left, right);
    }
};
// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}