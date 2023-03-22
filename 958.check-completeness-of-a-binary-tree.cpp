/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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

//  logic-> left subtree is complete but right subtree has only chil on left side but not on right side
// if right subtree have right child at the leaf but no left child at the leaf then it is false 
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int value=false;
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            TreeNode* node= q.front();
            q.pop();
            // suppose it is complete tree and its right subtree has only left child 
            // so last value that will be on q will be null so true 
            // complete tree ->1 2 3 4 5 6 null
            // not complete -> 1 2 3 4 5 null 7 -> null came but a node still present 
            if(node==NULL)
                value=true;
            else{
                if(value)
                    return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

//  last node on queue must be null so value = true
// whenever the node on q top is not null the return false


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        bool check = false;
        while(q.size()){
            auto node = q.front();
            q.pop();

            if(node==NULL){
                check = true;
                continue;
            }
            if(check)// if check value is true that means a null node is encountered 
                return false;
            
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};

// @lc code=end


int main(){

    return 0;
}