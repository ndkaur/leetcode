/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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

// need =-1  , have =0 , covered =1

class Solution { // T-o(n) ,s- o(n)
public:
    int cameras=0;
    int check(TreeNode* root){
        if(root==NULL) return 1; // no root consider it already covered 
        //  leaf node will be handled itself leaf-> left , right = null
        int lchild= check(root->left);
        int rchild= check(root->right);
         
        if(lchild==-1 || rchild==-1){ // no camera
            cameras++;
            return 0;
        }
        if(lchild == 0 || rchild==0){ // have camera means is covered
            return 1; // so the parent will be covered 
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(check(root)==-1){
            cameras++;
        }
        return cameras;
    }
};
// @lc code=end


int main(){

    return 0;
}