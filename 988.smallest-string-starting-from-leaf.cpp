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
class Solution0 { //O(N^2)
public:
    string ans=""; 
    void dfs(TreeNode* root, string temp){
        if(!root)
            return;
        temp = char(root->val+'a') + temp; // in worst case we have to go to n
        if(!root->left && !root->right){
            if(ans=="")
                ans = temp;
            else 
                ans = min(ans,temp);
        }

        if(root->left)
            dfs(root->left, temp);
        if(root->right)
            dfs(root->right, temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root)
            return ans;
        dfs(root,"");
        return ans;
    }
};


// bfs
class Solution { 
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root)
            return "";
        string ans="";

        queue<pair<TreeNode*, string>> q;
        q.push({root, string(1, char(root->val + 'a'))});

        while(q.size()){
            auto node = q.front().first;
            auto temp = q.front().second;
            q.pop();

            if(!node->left && !node->right){
                if(ans==""){
                    ans = temp;
                }
                else 
                    ans = min(ans, temp);
            }

            if(node->left)
                q.push({node->left, char(node->left->val+'a') + temp});
            if(node->right)
                q.push({node->right, char(node->right->val+'a')+temp});
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}