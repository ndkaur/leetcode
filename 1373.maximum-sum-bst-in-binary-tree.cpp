/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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

class NodeValue{
public:
    int mnVal;
    int mxVal;
    int mxSum;
};

class Solution {
public:
    NodeValue largest(TreeNode* root, int& sum){
        if(!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = largest(root->left,sum);
        auto right = largest(root->right, sum);

        if(left.mxVal< root->val && root->val<right.mnVal){
            sum = max(sum, root->val+left.mxSum+right.mxSum);
            return NodeValue(min(root->val, left.mnVal), max(root->val, right.mxVal), root->val+left.mxSum+right.mxSum);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.mxSum, right.mxSum));
    }
    int maxSumBST(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0;
        largest(root, sum);
        return sum>0 ? sum:0;
    }
};


//  finding the largest valid bst and count the sum side by side
class NodeValue{
public:
    int maxNode;
    int minNode;
    int maxSum;
    
    NodeValue(int minNode, int maxNode, int maxSum){
        this->minNode= minNode;
        this->maxNode= maxNode;
        this->maxSum= maxSum;
    }
};

class Solution { // t-> O(n)   s-> O(1)
private:
    NodeValue largest(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left= largest(root->left);
        auto right = largest(root->right);
        //  checking the condition of BST -> max of left < root < min of right 
        if(left.maxNode < root->val && root->val < right.minNode){
            sum=max(sum,root->val+ left.maxSum + right.maxSum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode),root->val+ left.maxSum+ right.maxSum);
        }
        return NodeValue(INT_MIN,INT_MAX, max(left.maxSum , right.maxSum));
    }

public:
    int sum=0;
    int maxSumBST(TreeNode* root) {
        largest(root);
        return sum>0 ? sum:0; 
    }
};
// @lc code=end


int main(){

    return 0;
}