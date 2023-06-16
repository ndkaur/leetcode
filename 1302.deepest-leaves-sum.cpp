/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

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
class Solution1 {
    int sum=0;
    int level =0;
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
    void dfs(TreeNode *root,int lev){
        if(!root) return ;
        if(root->left == NULL && root->right==NULL){
            if(lev>level){
                level=lev;
                sum=root->val;
            }
            else if(lev==level)
                sum+=root->val;
        }
        dfs(root->left,lev+1);
        dfs(root->right,lev+1);
    }
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        TreeNode* curr=root;
        queue<TreeNode*> q;
        q.push(curr);
        while(q.size()){
            // changing the val of sum to 0 so that each time it 
            // ony stores upto last sum recieved 
            sum=0;
            int depth=q.size();
            for(int i=0;i<depth;i++){
                curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return sum;
    }
};

class Solution0 {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum =0;
        vector<int> temp;
        while(q.size()){
            int sz = q.size();
            temp.clear();
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        for(int i=0; i<temp.size(); i++){
            sum += temp[i];
        }
        return sum;
    }
};

// @lc code=end


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}