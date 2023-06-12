/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
        else  // if occuring for first time 
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

//time -> O(N)  space->O(N)
class Solution {
public: 
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        map<int,int> mp;
        int mx =0;
        dfs(root,mp, mx);
        for(auto itr:mp){
            if(itr.second==mx){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
    void dfs(TreeNode* root, map<int,int>& mp , int& mx){
        if(!root) return;
        mp[root->val]++;
        mx = max(mx, mp[root->val]);
        if(root->left)
            dfs(root->left, mp, mx);
        if(root->right)
            dfs(root->right, mp,mx);
    }
};

// inorder time O(N) space O(1)
class Solution {
public: 
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        int curr_cnt =0;
        int mx_cnt =0;
        int prev_val = INT_MIN;
        dfs(root,mx_cnt, curr_cnt, prev_val,ans);
        return ans;
    }
    void dfs(TreeNode* root, int& mx_cnt, int& curr_cnt, int& prev_val, vector<int>& ans){
        if(!root) return;

        dfs(root->left, mx_cnt, curr_cnt, prev_val, ans);

        // curr_cnt
        if(root->val==prev_val)
            curr_cnt++;
        else curr_cnt =1;
        // mx_cnt
        if(curr_cnt == mx_cnt){
            ans.push_back(root->val);
        }
        else if(curr_cnt > mx_cnt){
            // now cnt is greater so change the arr and push new element in it
            ans.clear();
            ans.push_back(root->val);
            mx_cnt =  curr_cnt;
        }
        prev_val = root->val;

        dfs(root->right, mx_cnt, curr_cnt, prev_val, ans);
    }
};
// @lc code=end


int main(){

    return 0;
}