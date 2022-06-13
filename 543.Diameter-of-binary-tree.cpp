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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res= 0;
        solve(root,res);
        return res;
    }
    //  use the method to find height in binary tree
    int solve(TreeNode* root, int& res){
        if(root == NULL)
            return 0;
        int l= solve(root->left,res);
        int r= solve(root->right,res);
        res = max(res,l+r); // included the temp root
        return 1+max(l,r);
    }
};


int main(){
    Solution sol;
    
    return 0;
}