/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        deque<TreeNode*> Q;
        Q.push_back(root);
        bool reverse =true;

        while(!Q.empty()){
            int sz=Q.size();
            vector<int> level_nodes;
            deque<TreeNode*> dq;
            for(int i=0;i<sz;i++){
                TreeNode* n=Q.front();
                level_nodes.push_back(n->val);
                Q.pop_front();
                if(reverse){
                    if(n->left)
                        dq.push_front(n->left);
                    if(n->right)
                        dq.push_front(n->right);
                }
                else{
                    if(n->right)
                        dq.push_front(n->right);
                    if(n->left)
                        dq.push_front(n->left);
                }
            }
            Q.insert(Q.end(),dq.begin(),dq.end());
            result.push_back(level_nodes);
            reverse=!reverse;
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        bool leftToRight=true;
        q.push(root);
        while(q.size()){
            int sz= q.size();
            vector<int> row(sz);
            for(int i=0;i<sz;i++){
                TreeNode* node= q.front();
                q.pop();
                // if left to right direction then idx is i otherwise fill in reverse manner
                int idx= leftToRight ? i : (sz-i-1); 
                row[idx]= node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                //  change the directions 
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end



int main(){
    Solution sol; 
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(input);
    vector<vector<int>> out = sol.zigzagLevelOrder(root);
    for(auto x:out){
        print(x);
    }
    return 0;
}