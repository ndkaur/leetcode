/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        int mxdepth =0;
        int leftValue=root->val;
        dfs(root,mxdepth,leftValue,0);
        return leftValue;
    }

    void dfs(TreeNode* root, int& mxdepth , int& leftValue,int depth ){
        if(!root) 
            return;
        dfs(root->left,mxdepth,leftValue,depth+1);
        dfs(root->right,mxdepth,leftValue,depth+1);
        if(depth>mxdepth){
            mxdepth=depth;
            leftValue=root->val;
        }
    }
};
//bfs 

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int last;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz= q.size();
            for(int i=0; i<sz; i++){
                auto node= q.front();
                q.pop();
                // every time in q at i=0 willl be the left node present
                if(i==0)
                    last = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return last;
    }
};
// @lc code=end


int main(){
   
    return 0;
}