/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int res=0;
    int sum;
    vector<int> seen={0};
    void dfs(TreeNode* root, long long partialSum=0){
        partialSum+= root->val;
        for(auto s:seen){
            if(s==partialSum- sum)
                res++;
        }
        seen.push_back(partialSum);
        if(root->left)
            dfs(root->left, partialSum);
        if(root->right)
            dfs(root->right, partialSum);
        seen.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
       sum= targetSum;
       if(!root) return res;
       dfs(root);
       return res;
    }
};

class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root, long long sum){
        if(!root) return;
        if(root->val==sum) 
            ans++;
        dfs(root->left, sum-root->val);
        dfs(root->right, sum-root->val);
    }

    int pathSum(TreeNode* root, int sum) {
        if(root){
            dfs(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}