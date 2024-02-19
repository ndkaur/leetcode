/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!= NULL && root->val!= val){
            root= (root->val>val)? root->left : root->right;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val== val)
            return root;
        if(root->val>val)
            return searchBST(root->left,val);
        else 
            return searchBST(root->right,val);
    }
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            if(top->val == val) {
                return top;
            } else if(top->val<val) { // val exist on right isde so no need of left side 
                top->left = NULL;
            } else {
                top->right = NULL;
            }
            if(top->left) {
                st.push(top->left);
            }
            if(top->right) {
                st.push(top->right);
            }
        }
        return NULL;
    }
};

// @lc code=end


int main(){

    return 0;
}