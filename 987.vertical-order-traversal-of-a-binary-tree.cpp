/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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

//  queue ->(node, { vertical, level})
//  map -> {vertical , level , {values of nodes at same level}}
class Solution {  // t-> O(n)    s-> O(n)
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode* , pair<int ,int>>> q;
        q.push({root,{0,0}}); // first node vertical and level is 0,0
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* node= p.first;
            int x = p.second.first; // vertical
            int y = p.second.second; // level 
            mp[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto m:mp){
            vector<int> temp;
            for(auto p:m.second){
                temp.insert(temp.end(),p.second.begin(), p.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end


int main(){

    return 0;
}