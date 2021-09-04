/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {4
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
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
    vector<TreeNode*> generate(int start,int end){
        vector<TreeNode*> ans;
        if(end-start<0)  ans.push_back(0);
        if(end-start==0) ans.push_back(new TreeNode(start));
        if(end-start>0){
            for(int i=start;i<=end;i++){
                vector<TreeNode*> l=generate(start,i-1);
                vector<TreeNode*> r=generate(i+1,end);
                for(int j=0;j<l.size();j++){
                    for(int k=0;k<r.size();k++){
                        TreeNode* extra= new TreeNode(i);
                        extra->left= l[j];
                        extra->right = r[k];
                        ans.push_back(extra);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    int n= 3;
    vector<TreeNode*> ans = sol.generateTrees(n);
    print(ans);
    return 0;
}