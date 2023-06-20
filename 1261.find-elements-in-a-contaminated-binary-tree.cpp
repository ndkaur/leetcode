/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
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

class FindElements {
public:
    set<int> s;
    FindElements(TreeNode* root) {
        root->val =0;
        s.insert(0);
        dfs(root);
    }

    void dfs(TreeNode* root){
        if(!root)
            return;
        if(root->left){
            root->left->val = 2*root->val + 1;
            s.insert(2*root->val+1);
            dfs(root->left);
        }
        if(root->right){
            root->right->val = 2*root->val +2;
            s.insert(2*root->val+2);
            dfs(root->right);
        }
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end


int main(){

    return 0;
}