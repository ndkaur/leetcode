/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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
    string ans="~";
public:
    void dfs(TreeNode* root, string s){
        if(!root) return;
        // when reached leaf node
        
        if(!root->left && !root->right){
            ans= min(ans,char(root->val+'a')+s);
        }
        dfs(root->left,char(root->val+'a')+s);
        dfs(root->right,char(root->val+'a')+s);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};

class Solution {
public:
    string ans="";
    void dfs(TreeNode* root, string s){
        
        // when reached leaf node
        s= char(root->val+'a')+s;
        if(!root->left && !root->right){
            if(ans=="") ans=s;
            else
                ans= min(ans, s);
        }
        if(root->left) 
            dfs(root->left,s);
        if(root->right)
            dfs(root->right,s);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(!root) return ans;
        dfs(root,"");
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}