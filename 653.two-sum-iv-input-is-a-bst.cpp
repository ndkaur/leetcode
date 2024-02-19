/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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

// tc-> O(n)  sc->O(n)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&in){
        if(root == NULL) return ;
        inorder(root->left, in) ;
        in.push_back(root->val) ;
        inorder(root->right, in) ;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr) ;
        // sorted arr
        int i = 0;
        int j = arr.size()-1 ;
        while(i < j){
            int sum = arr[i] + arr[j] ;
            if(sum == k) return true;
            else if(sum > k) 
                j--;
            else 
                i++;
        }
        return false ;
    }
};

class Solution1 {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root,s,k);
    }
    bool dfs(TreeNode* root, unordered_set<int>& s, int k){
        if(!root) return false;
        if(s.count(k - root->val))
            return true;
        s.insert(root->val);
        return dfs(root->left,s, k) || dfs(root->right,s, k);
    }
};

// @lc code=end


int main(){

    return 0;
}