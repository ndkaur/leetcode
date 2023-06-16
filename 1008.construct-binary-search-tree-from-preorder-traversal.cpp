/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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

// tc-> O(nlogn)+ O(n) 
//  sc-> O(n)+ O(n)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        vector<int> inorder(n);
        inorder= preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int> inmp;
        for(int i=0;i<n;i++)
            inmp[inorder[i]]=i;
        int preStart=0;
        int preEnd= n-1;
        int inStart= 0;
        int inEnd= inorder.size()-1;
        TreeNode* root= findTree(preorder, preStart, preEnd, inorder, inStart, inEnd, inmp);
        return root;
    }
    TreeNode* findTree(vector<int>& preorder, int preStart, int preEnd , vector<int>& inorder, int inStart, int inEnd, map<int,int>& inmp){
        if(preStart>preEnd || inStart> inEnd)
                return NULL;
        TreeNode* root= new TreeNode(preorder[preStart]);
        int inRoot= inmp[root->val];
        int numLeft= inRoot- inStart;
        root->left= findTree(preorder, preStart+1, preStart+ numLeft , inorder, inStart, inRoot-1,inmp);
        root->right = findTree(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, inmp);
        return root;
    }
};


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        if(n==0) return NULL;
        int i=0;
        return build(preorder, i, INT_MAX);
    }
    TreeNode* build(vector<int>& pre , int& i, int mx){
        if(i == pre.size() || pre[i] > mx){
            return NULL;
        }
        TreeNode* root= new TreeNode(pre[i++]);
        root->left = build(pre, i, root->val);
        root->right = build(pre, i, mx);
        return root;
    }
};



class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n= preorder.size();
        if(n==0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1; i<n; i++){
            TreeNode* curr = root;
            while(true){ // what is one element is less than root and the next is also less so keep on checking
                if(curr->val > preorder[i]){ // root > key  small key can be found on left side 
                    if(curr->left == NULL){
                        curr->left = new TreeNode(preorder[i]);
                        break;
                    }
                    else
                        curr= curr->left;
                }
                else{ // root < key   greater key can be found on the right side 
                    if(curr->right == NULL){
                        curr->right = new TreeNode(preorder[i]);
                        break;
                    }
                    else 
                        curr = curr->right;
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