/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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


// time O(N∗N)
// spce O(N)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return make(0, n-1, nums);
    }
    TreeNode* make(int l, int r, vector<int>& nums){
        if(l>r) return NULL;
        int mx = nums[l];
        int idx = l;
        for(int i=l; i<=r; i++){
            if(nums[i]>mx){
                mx = nums[i];
                idx =i;
            }
        }
        TreeNode* root = new TreeNode(mx);
        root->left = make(l, idx-1, nums);
        root->right = make(idx+1, r, nums);
        return root;
    }
};

// @lc code=end


int main(){

    return 0;
}