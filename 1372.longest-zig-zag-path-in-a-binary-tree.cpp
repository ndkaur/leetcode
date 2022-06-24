/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int maxStep=0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0); // go in left 
        dfs(root, false, 0); // go in right 
        return maxStep;
    }
    //  at every node we have 2 choices -> go left , go right
    void dfs(TreeNode* root, bool isLeft , int step){
        if(!root) return;
        maxStep = max(maxStep,step);
        if(isLeft){ // can go in left
            dfs(root->left, false, step+1); // keep going left
            dfs(root->right, true, 1); // restart a new path 
        }else{ // cant go in left
            dfs(root->right, true, step+1); // keep going right
            dfs(root->left, false, 1); // new path start 
        }
    }
};
// @lc code=end


int main(){

    return 0;
}