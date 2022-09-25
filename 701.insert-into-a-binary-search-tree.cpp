/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr=root, *prev=NULL;
        if(!root) return new TreeNode(val);
        // prev is used to store the parent position of the val that will be added 
        // prev is parent of curr 
        while(curr){
            prev=curr;
            if(val<curr->val)
                curr=curr->left;
            else 
                curr=curr->right;
        }
            
        if(val<prev->val)
            prev->left = new TreeNode(val); 
        else 
            prev->right = new TreeNode(val);
        return root;
    }
};

//t->O(n)
// s->O(h) or O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) 
            return new TreeNode(val);
        if(root->val < val){
            if(root->right!=NULL)
                insertIntoBST(root->right,val);
            else 
                root->right= new TreeNode(val);
        }
        else{
            if(root->left!=NULL)
                 insertIntoBST(root->left,val);
            else 
                root->left= new TreeNode(val);
        }
        return root;
    }
};

// recursive  O(N)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) 
            return new TreeNode(val);
        if(root->val < val){
            root->right= insertIntoBST(root->right,val);
        }
        else{
            root->left=insertIntoBST(root->left,val);
        }
        return root;
    }
};

// iterative
// log base 2 N  -> height balenced tree
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr=  root;
        while(true){
            if(curr->val <= val){
                if(curr->right){
                    curr = curr->right;
                } 
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{ // curr->val > val
                if(curr->left){
                    curr= curr->left;
                }
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
// @lc code=end


int main(){
    
}