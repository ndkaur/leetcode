/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */

// @lc code=start

//   Definition for a binary tree node.

#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
#include "Tree.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

void print_vv(vector<vector<int>> &out){
    for(auto x: out) 
        print(x);
}

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> out;
        vector<TreeNode*> q; 
        if(root) // in that case when tree is empty
            q.push_back(root);
        
        while(q.size()){ // till the time q has some roots in it
            vector<TreeNode*> newq;
            out.push_back({}); // its a vvi insert bracket to create space for vi
            for(auto node: q){
                out.back().push_back(node->val);
                if(node->left)
                    newq.push_back(node->left);
                if(node->right)
                    newq.push_back(node->right);
            }
            q=newq;
        }
        reverse(out.begin(),out.end());
        return out;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++){
                TreeNode* node= q.front();
                q.pop();
                if(node->left) 
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// @lc code=end


int main(){
    Solution sol; 
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(input);
    vector<vector<int>> out = sol.levelOrderBottom(root);
    print_vv(out);
    return 0;
}