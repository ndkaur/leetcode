/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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


//  O(n)
// O(h)
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        auto mn=INT_MAX;
        // val is that which store the main root val
        int val= -1;
        return dfs(root,mn, val);
    }
    int dfs(TreeNode* root, int &mn , int& val){
        if(root->left)
            dfs(root->left,mn,val);
        
        if(val>=0)
                mn= min(mn, abs(root->val- val));
            //update the root value
        val = root->val;
        
        if(root->right)
            dfs(root->right, mn, val);
        return mn;
    }
};


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int mn=INT_MAX;
        int val= -1;
        return dfs(root,mn, val);
    }
    int dfs(TreeNode* root, int &mn , int& val){
        if(root->left)
            dfs(root->left,mn,val);
        
        if(val>=0)
                mn= min(mn, abs(root->val- val));
        val = root->val;
        
        if(root->right)
            dfs(root->right, mn, val);
        return mn;
    }
};

// @lc code=end


int main(){

    return 0;
}