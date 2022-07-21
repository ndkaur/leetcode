/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode* root){
        if(!root) return {};
        vector<int> ans;
        int val= INT_MIN; 
        int mx=0;
        int curr=0;
        dfs(root, ans,val,mx, curr);
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& ans, int& val, int& mx, int& curr){
        if(!root) return ;
        
        dfs(root->left,ans,val, mx, curr);
        // calculate the occurence of each node 
        if(root->val==val)
            curr++;
        else  // if occuring fro first time 
            curr=1;
        // finding the max among all
        if(curr>mx){
            // clear is important otherwise all the nodes gets added 
            ans.clear();
            mx= curr;
            ans.push_back(root->val);
        }
        else if(curr== mx)
            ans.push_back(root->val);
        // giving the next val to node 
        val= root->val;
            
        dfs(root->right, ans, val, mx, curr);
    }
};

// @lc code=end


int main(){

    return 0;
}