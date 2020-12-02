/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(!root) return NULL;
        if(!root->left) 
            return 1+minDepth(root->right);
        if(!root->right)
            return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
       if(!root) return NULL;
       queue<TreeNode *> q;
       q.push(root);
       int depth=0;
       while(!q.empty()){
           depth++;
           int n=q.size();
           for(int i=0;i<n;i++){
               TreeNode *curr= q.front();
               q.pop();
               if(!curr->left && !curr->right)
                    return depth;
               if(curr->right) q.push(curr->right);
               if(curr->left) q.push(curr->left); 
           }
       }
       return -1;
    }
};
// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}