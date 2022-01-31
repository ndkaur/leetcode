/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
 */

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

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> s1,s2;
        vector<int> ans;
        while(root1 || root2 || !s1.empty() || !s2.empty()){
            while(root1!=NULL){
                s1.push(root1);
                root1 = root1->left;
            }
            while(root2!=NULL){
                s2.push(root2);
                root2= root2->left;
            }
            if(s2.empty() || (!s1.empty() && s1.top()->val<= s2.top()->val)){
                root1= s1.top();
                s1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }
            else{ // s1 is empty
                root2= s2.top();
                s2.pop();
                ans.push_back(root2->val);
                root2= root2->right;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}