/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
private:
    int find(TreeNode* node , int& ans){
        if(!node) return 0;
        int l = (node->left)? find(node->left, ans) : 0;
        int r= (node->right) ? find(node->right, ans) : 0;
        int resl= node->left && node->left->val == node->val ? l+1 :0;
        int resr= node->right && node->right->val == node->val ? r+1 :0;
        ans = max(ans, resl+ resr); // this is to store the ultmate answer
        return max(resl, resr); // this is what root returns to its parent root 
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans =0;
        find(root, ans);
        return ans;
    }
    
};
// @lc code=end


int main(){

    return 0;
}