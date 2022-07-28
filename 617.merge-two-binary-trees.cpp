/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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

// making the changes in tree1 instead of making a new tree
//O(N)    O(N)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
    TreeNode* dfs(TreeNode* root1, TreeNode* root2){
        if(!root1) return root2;
        if(!root2) return root1;
        if(!root1 && !root2) return NULL;
        
        root1->val = root1->val+ root2->val;
        root1->left= dfs(root1->left, root2->left);
        root1->right= dfs(root1->right, root2->right);
        return root1;
    }
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        stack<TreeNode*> s1, s2;
        TreeNode* ans=root1;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty()){
            TreeNode* c1= s1.top();
            TreeNode* c2= s2.top();
            s1.pop();
            s2.pop();
            
            c1->val+= c2->val;

            if(!c1->right && c2->right){
                c1->right= c2->right;
            }
            else if(c1->right && c2->right){
                s1.push(c1->right);
                s2.push(c2->right);
            }
            if(!c1->left && c2->left){
                c1->left= c2->left;
            }
            else if(c1->left && c2->left){
                s1.push(c1->left);
                s2.push(c2->left);
            }
        }
        return ans;
    }
};






// @lc code=end


int main(){

    return 0;
}