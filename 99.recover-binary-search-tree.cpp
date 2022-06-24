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
class Solution { // tc->O(n) sc->O(1)
public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        // correct ->  prev val < root val
        //  checking for violations 
        if(prev!=NULL && (prev->val > root->val)){
            if(first==NULL){ // first time violation
                first= prev;
                middle= root;
            }
            else{ // first is not null ie second violation
                last= root;
            }
        }
        prev=root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first= middle= last= NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        // swap to get he correct order
        // case 1 -> when only one violation occur 
        if(first && middle)
            swap(first->val , middle->val);
        //  case 2 -> when two violations occur 
        if(first && last)
            swap(first->val , last->val);
    }
};
// @lc code=end


int main(){

    return 0;
}