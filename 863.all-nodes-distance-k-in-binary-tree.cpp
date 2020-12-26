/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    map<TreeNode*,TreeNode*> parent; // to save the value of parent and its child
    set<TreeNode*> visit; // to mark the visit or not 

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        find_parent(root);
        distance_ans(target,k); // have to find the values of roots from the target at k distance 
        return ans;
    }

    void distance_ans(TreeNode* root, int k){
        if(visit.find(root) != visit.end())
            return;
        visit.insert(root);
        if(k==0){ // at the same location 
            ans.push_back(root->val); // insert the current root 
            return;
        }
        if(root->left)
            distance_ans(root->left,k-1);
        if(root->right)
            distance_ans(root->right,k-1);
        TreeNode* p = parent[root];
        if(p) 
            distance_ans(p,k-1);
    }

    void find_parent(TreeNode* root){
        if(!root) return;
        if(root->left) {
            parent[root->left] = root; // saved value of root in place of root->left
            find_parent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            find_parent(root->right);
        }
    }
};
// @lc code=end


int main(){

    return 0;
}