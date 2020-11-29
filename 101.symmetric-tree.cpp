/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

//dfs
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root, root);
    }
    bool dfs(TreeNode *t1, TreeNode *t2){
        if(t1==NULL && t2==NULL) return true;
        if(t1==NULL || t2== NULL) return false;
        return (t1->val==t2->val) && dfs(t1->right,t2->left) && dfs(t1->left , t2->right);
    }
};
// @lc code=end

//bfs

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        TreeNode *curr =root;
        q.push(curr);
        q.push(curr);
        while(!q.empty()){
            TreeNode *t1=q.front();
            q.pop();
            TreeNode *t2 =q.front();
            q.pop();

            if(!t1 && !t2)continue;
            if(!t1 || !t2) return false;
            if(t1->val!=t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }   
};
int main(){
   
    return 0;
}