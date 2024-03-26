/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    void check(TreeNode *root, int par, int depth, unordered_map<int,pair<int,int>> &m){
        if(!root)
            return;
        m[root->val] = {par,depth};
        check(root->left, root->val, depth+1, m);
        check(root->right, root->val, depth+1, m);
    }

    bool isCousins(TreeNode* root, int x, int y){
        // node -> {parent, depth  }
        unordered_map<int,pair<int,int>> m;
        // for each node store the vlaues of parent and depth  
        check(root, INT_MIN, 0, m);
        // nodes x and y exist in map and there dpeth sma e, but parent different
        if(m.find(x)!=m.end() && m.find(y)!=m.end() && m[x].second==m[y].second && m[x].first!=m[y].first)
            return true;
        return false;    
    }
};

// conditon is both x and y must not belong to same parent and depth must be equal
// so check depth as well as parent  
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xdep= -1;
        int ydep= -1;
        TreeNode* xpar= findDepth(root, x, 0, xdep);
        TreeNode* ypar= findDepth(root, y,0, ydep);

        if(xdep != ydep || xpar == ypar)
            return false;
        return true;
    }
    TreeNode* findDepth(TreeNode* root, int val, int depth, int& level){
        if(!root) return NULL;
        // when any of the root children is equal to the given x or y 
        if((root->left && root->left->val == val) || (root->right && root->right->val==val)){
            // update the level
            level= depth;
            // root is the parent node of x or y 
            return root;
        }
        // level is used to store the actual depth 

        TreeNode* left= findDepth(root->left, val, depth+1 , level);
        if(left) 
            return left;
        TreeNode* right = findDepth(root->right, val, depth+1, level);
        if(right) 
            return right;
        return NULL;
    }
};


class Solution {
public:
    int dx, dy, px, py;
    
    bool isCousins(TreeNode* root, int x, int y) {
        // same depth but different parents
        if(root->val==x || root->val == y)
            return false;
        // root, x, y, cur depth, cur parent
        find(root, x, y, 0, 0);

        if(dx==dy && px!=py)
            return true;
        return false;
    }
    void find(TreeNode* root, int x, int y, int curDepth, int curParent){
        if(!root) return;
        if(root->val==x){
            px = curParent;
            dx = curDepth;
            return;
        }
        if(root->val==y){
            py = curParent;
            dy = curDepth;
            return;
        }
        find(root->left, x, y, curDepth+1, root->val);
        find(root->right, x, y, curDepth+1, root->val);
    }
};


// @lc code=end


int main(){

    return 0;
}