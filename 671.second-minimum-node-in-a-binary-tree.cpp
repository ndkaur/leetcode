/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return 0;
        set<int> s; // sorted and increasing order
        dfs(root, s);
       if(s.size()==1)
        return -1;
        // we want second min val
        auto it= s.begin();
        //move it ahead
        it++;
        // get the secod min val
        return *it;
    }
    void dfs(TreeNode* root, set<int>& s){
        if(!root) return;
        dfs(root->left,s);
        s.insert(root->val);
        dfs(root->right, s);
    }
};


// @lc code=end


int main(){

    return 0;
}