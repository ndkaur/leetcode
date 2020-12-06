/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
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
    int sum=0;
public:
    int sumEvenGrandparent(TreeNode* root) {
        func(root,NULL,NULL);
        return sum;
    }
    void func(TreeNode *root ,TreeNode* parent, TreeNode *grandparent){
        if(!root) return;
        if( grandparent && grandparent->val%2==0)
            sum=sum+root->val;
        func(root->left,root,parent);
        func(root->right, root, parent);
    }
};

//bfs

class Solution {
public:
    int fun(TreeNode *root){
        return root ? root->val:0;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->val%2==0){
                if(curr->left) 
                    sum+= fun(curr->left->left)+fun(curr->left->right);
                if(curr->right)
                    sum+= fun(curr->right->left)+fun(curr->right->right);
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return sum;
    }
};
// @lc code=end

int main(){
   
    return 0;
}

