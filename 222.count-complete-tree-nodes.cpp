/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
class Solution { //O(n)
public:
    int countNodes(TreeNode* root) {
        int x,y;
        if(root!=NULL){
            x= countNodes(root->right);
            y= countNodes(root->left);
            return(x+y+1);
        }
        return 0;
    }
};

// if pur complete binary tree is a perfect binary tree 
// then only the property of  2^h -1 will be applied 
// so we need to check if our complete bt is a perfect bt or not 
// for that left height must be equal to right height 
// if lh == rh then ans =  2^h-1
// but if lh!= rh then 
// we need  to find it seprately for left child and right child 
// time ->  log2(n+1) kind of similar to binary search 

//  nodes in complete bt are = 2^h -1 
class Solution { //tc-> O(logn)^2   sc->O(logN)
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh= findlh(root);
        int rh= findrh(root);
        if(lh==rh)
            return (1<<lh)-1; // 2^h
            // return pow(2,lh)-1; // 2^h
        return 1+countNodes(root->left) + countNodes(root->right);
    }
    int findlh(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node= node->left;
        }
        return h;
    }

    int findrh(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node= node->right;
        }
        return h;
    }
};
//  not all nodes are getting traversed 

class Solution {
public:
    int countNodes(TreeNode* root) {
        int lh =0;
        int rh =0;
        TreeNode* l = root; 
        while(l){
            lh++;
            l= l->left;
        }
        TreeNode* r= root;
        while(r){
            rh++;
             r= r->right;
        }
        if(lh == rh){ // 2^ h-1
            return (1<<lh) - 1;
        }
        return 1 +  countNodes(root->left) + countNodes(root->right);
    }
};



class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto node = q.front();
            q.pop();
            cnt++;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return cnt;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> roots =treeNodeToString(root);
    int ans = sol.countNodes(roots);
    cout<<ans;
    return 0;
}