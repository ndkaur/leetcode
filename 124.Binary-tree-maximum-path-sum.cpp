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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
    int solve(TreeNode* root,int& res){
        if(root==NULL)
            return 0;
        int l=solve(root->left,res);
        int r= solve(root->right,res);
        int temp= max(max(l,r)+root->val , root->val); // -ve
        int ans = max(temp,l+r+root->val);
        res= max(res,ans);
        return temp;
    }
};

// temp  max(include left, include right)+ root->val 
// but if both results into negative then it will reduced the actual result 


int main(){
    
    return 0;
}