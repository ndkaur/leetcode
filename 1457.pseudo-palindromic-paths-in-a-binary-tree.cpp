/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
class Solution {
    int count=0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count;
    }
    void preorder(TreeNode *root, int times){
        if(root != NULL){
            //no of occurence 
            times = times ^ (1<<root->val);
            // if pseudo or not 
            if(root->left ==NULL && root->right == NULL){
                // frequency as 1 of at most one digit 
                if(times & (times-1) ==0)
                    count++;
            }
            preorder(root->left , times);
            preorder(root->right,times);
        }
    }
};

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int cnt =0;
        dfs(root,mp,cnt);
        return cnt;
    }
    void dfs(TreeNode* root,unordered_map<int,int> mp, int& cnt){
        if(!root) return ;
        mp[root->val]++;
        if(!root->left && !root->right){
            int odd =0;
            for(auto itr:mp){
                if(itr.second %2==1) // odd occurence
                    odd++; // count of numbers with odd occurence 
            }
            // the the count of odd occuring numbers is less than 1 can be put in the center to make a palindrome
            if(odd<=1)
                cnt++;
        }
        if(root->left)
            dfs(root->left,mp, cnt);
        if(root->right)
            dfs(root->right, mp, cnt);
    }
};
// @lc code=end


int main(){

    return 0;
}