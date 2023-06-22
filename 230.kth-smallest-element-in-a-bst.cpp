/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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

//  t->O(h+k)
// s->O(h+k)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        vector<int> in;
        inorder(root,in);
        return in[k-1];
    }
    void inorder(TreeNode* root, vector<int>& in){
        if(!root) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
};

//  t->O(h+k)
// s->O(h+k)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        stack<TreeNode*> st;
        TreeNode* curr= root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr= st.top();
            st.pop();
            k--;
            if(k==0)
                ans= curr->val;
            curr= curr->right;
        }
        return ans;
    }
};

// O(nlogk),
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        find(root, k, pq);
        return pq.top();
    }
    void find(TreeNode* root, int k, priority_queue<int>& pq){
        if(!root) return;
        if(pq.size()<k)
            pq.push(root->val);
        else if(root->val < pq.top()){
            pq.pop();
            pq.push(root->val);
        }
        find(root->left, k, pq);
        find(root->right, k, pq);
    } 
};
// @lc code=end


int main(){

    return 0;
}