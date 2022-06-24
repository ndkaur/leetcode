/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
// #include "LinkedList.h"

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
    TreeNode* buildTree_rec(vector<int>& inorder,int i1,int i2, vector<int>& postorder,int p1,int p2){
        if(i1>=i2 || p1>=p2) return nullptr;
        TreeNode *root= new TreeNode(postorder[p2-1]);
        auto it=find(inorder.begin()+i1,inorder.begin()+i2,postorder[p2-1]);
        int diff=it-inorder.begin()-i1;
        root->left =buildTree_rec(inorder,i1,i1+diff,postorder,p1,p1+diff);
        root->right = buildTree_rec(inorder,i1+diff+1,i2,postorder,p1+diff,p2-1);

        return root; 
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0) return nullptr;

        return buildTree_rec(inorder,0,n,postorder,0,n);
    }
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!= postorder.size())
            return NULL;
        map<int, int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1 , inorder,0, inorder.size()-1,inMap);
    }
    TreeNode* build(vector<int>& postorder, int pStart, int pEnd , vector<int>& inorder, int inStart, int inEnd , map<int,int>& inMap){
        if(pStart> pEnd || inStart > inEnd) 
            return NULL;
        TreeNode* node= new TreeNode(postorder[pEnd]);
        int inRoot= inMap[node->val];
        int numLeft= inRoot - inStart;

        node->left= build(postorder,pStart,pStart+numLeft-1 , inorder, inStart, inRoot-1, inMap);
        node->right= build(postorder,pStart+numLeft,pEnd-1 , inorder,inRoot+1, inEnd, inMap);
        return node;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
    TreeNode *ans=sol.buildTree(inorder,postorder);
    print(ans);
    return 0;
}