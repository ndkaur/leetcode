/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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


// full binary tree can only have odd number of roots on its both left and right side 
// cause the rule is either the root can have 0 children or 2 children 
// and suppose n = 5   1 2 3 4 5  we will choose the nodes one by one to make them root 
// but not all nodes can become the root cause each root must have odd number of roots remaining on its both sides
// 1 2 3 4 5   choose 1 left side 0 children, right side  4 children even not possible 
// choose 2 -> left side 1 child , right side 3 child possible 
// choose 3 -> lft side 2 children , right side 2 child  not possible 
// so our loop will go at pace of 2 i+=2

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        // considering 0 base indexing 
        if(n==1){ 
            ans.push_back(new TreeNode(0));
            return ans;
        }
        // node can only have odd number of children on both side
        for(int i=1; i<n; i+=2){
            // 0 1 2 3 4 5 6  let i=3 left = 3, right =7-3-1=3
            // number of children on left side 
            vector<TreeNode*> left = allPossibleFBT(i);
            // number of children on right side
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            //now joining the results from left and right side as one tree
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n<1 || n%2==0){
            return ans;
        }
        for(int k=2;k<n;k+=2){
            vector<TreeNode*> v1 =allPossibleFBT(k-1);
            vector<TreeNode*> v2 =allPossibleFBT(n-k);
            int n1=v1.size();
            int n2=v2.size();
            for(int i=0;i<n1;i++){
                for(int j=0;j<n2;j++){
                    TreeNode* newroot= new TreeNode(0);
                    newroot->left=v1[i];
                    newroot->right= v2[j];
                    ans.push_back(newroot);
                }
            }
        }
        if(ans.empty()){
            if(n==1)
                ans.push_back(new TreeNode(0));
        }
        return ans;
    }
};
// @lc code=end

int main(){
    
    return 0;
}