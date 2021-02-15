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