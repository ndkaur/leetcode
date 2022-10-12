/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        // if depth is 1 then add at begining 
        if(depth == 1){
            TreeNode* newTree = new TreeNode(val);
            newTree->left = root;
            return newTree;
        }
        insert(root, val, depth, 1);
        return root;
    }
    void insert(TreeNode* root, int val, int depth, int newDepth){
        if(!root)
            return;
        if(newDepth == depth-1){
            TreeNode* l= root->left;
            root->left = new TreeNode(val);
            root->left->left= l;

            TreeNode* r= root->right;
            root->right = new TreeNode(val);
            root->right->right = r;
        }
        else{
            insert(root->left, val, depth, newDepth+1);
            insert(root->right, val, depth, newDepth+1);
        }
    }
};
// @lc code=end


int main(){

    return 0;
}