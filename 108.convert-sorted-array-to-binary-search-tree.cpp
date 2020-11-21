/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n =nums.size();
        if(!n) return NULL;
        int l=0;
        int r=n-1;
        return dfs(nums,l,r);
    }
    TreeNode *dfs(vector<int> nums, int l,int r){
        if(l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode *mnode=new TreeNode(nums[mid]);
        mnode->left =dfs(nums,l,mid-1);
        mnode->right=dfs(nums,mid+1,r);
        return mnode;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vi a = {1,2,3,4,5};
    TreeNode* root = sol.sortedArrayToBST(a);
    string s = treeNodeToString(root);
    deb(s);
    return 0;
}
  

// @lc code=end
