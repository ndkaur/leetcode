/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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

//dfs
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum =0;
        return dfs(root,sum);
    }
    int dfs(TreeNode* root, int sum){
        if(!root)
            return 0;
        // 1*10+2 = 12 
        //1*10+3 = 13 
        // 12+13 = 25 
        sum = sum*10+ root->val;
        if(root->left==NULL && root->right==NULL)
            return sum;
        int lftsum = dfs(root->left, sum);
        int rgtsum = dfs(root->right,sum);
        return lftsum+rgtsum;
    }
};

//bfs
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum =0;
        queue<pair<TreeNode*,int>> q; // node, sum
        q.push({root,0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            TreeNode* node = t.first;
            int curSum = t.second;
            curSum = curSum*10 + node->val;
            if(node->left==NULL && node->right==NULL)
                sum += curSum;
            if(node->left)
                q.push({node->left, curSum});
            if(node->right)
                q.push({node->right, curSum}); 
        }   
        return sum;
    }
};
// @lc code=end


int main(){

    return 0;
}