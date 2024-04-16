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


// dfs 
class Solution0 {
public:
   
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return NULL;

        if(depth==1){
            TreeNode* newTree = new TreeNode(val);
            newTree->left  = root;
            return newTree;
        }
        findDepth(root, val, 1, depth);
        return root;
    }
     void findDepth(TreeNode* root, int val, int d, int depth){
        if(!root)
            return;
        // we want 1 level behind so that we can insert new node val
        if(d==depth-1){
            TreeNode* l = root->left;
            root->left = new TreeNode(val);
            root->left->left = l;

            TreeNode* r = root->right;
            root->right = new TreeNode(val);
            root->right->right = r;
        }
        else{
            findDepth(root->left, val, d+1, depth);
            findDepth(root->right, val, d+1, depth);
        }
    }
};

// bfs
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return NULL;

        if(depth==1){
            TreeNode* newTree = new TreeNode(val);
            newTree->left  = root;
            return newTree;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d = 0;

        while(q.size()){
            int sz= q.size();
            d++;
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();
                if(d==depth-1){
                    TreeNode* l = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = l;

                    TreeNode* r = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = r;
                }
                else{
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
            }
        }
        return root;
    }
};


// @lc code=end


int main(){

    return 0;
}