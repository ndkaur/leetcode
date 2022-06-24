/*
 * @lc app=leetcode id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
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
class Solution {  //t->O(n) s->O(n)
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz= q.size();
            int prev= level%2 ==0 ? 0 : INT_MAX;
            while(sz--){
                TreeNode* node= q.front();
                q.pop();
                if(level%2==0){ // even level -> node val must be odd  and increasing
                    if(node->val % 2 ==0 || node->val<=prev)
                        return false;
                } else{ // odd level-> node val must be even and decreasing
                    if(node->val %2 || node->val>=prev)
                        return false;
                }
                prev= node->val;
                if(node->left!=NULL) 
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};
// @lc code=end


int main(){

    return 0;
}