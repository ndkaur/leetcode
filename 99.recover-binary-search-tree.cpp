/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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

// tc->O(n) sc->O(1)
class Solution {
public:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev= NULL;
    
    void recoverTree(TreeNode* root) {
        first= middle= last=NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        // non adjacent nodes 
        if(first && last)
            swap(first->val, last->val);
        // adjacent nodes 
        else if(first && middle)
            swap(first->val, middle->val);
    }
    // prev first middle last 
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        if(prev!=NULL && (root->val< prev->val)){
            if(first==NULL){
                first= prev;
                middle= root;
            }
            else 
                last= root;
        }
        prev= root;
        inorder(root->right);
    }
};
// @lc code=end


int main(){

    return 0;
}