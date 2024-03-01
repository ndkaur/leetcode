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
    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    void addLeft(TreeNode* root, vector<int>& ans){
        TreeNode* curr = root->left;
        while(curr){
            if(!isLeaf(curr)){
                ans.push_back(curr->val);
            }
            if(curr->left)
                curr= curr->left;
            else 
                curr= curr->right;
        }
    }
    void addLeaf(TreeNode* root, vector<int>& ans){
        if(isLeaf(root)){
            ans.push_back(root->val);
            return;
        }
        if(root->left){
            addLeaf(root->left, ans);
        }
        if(root->right){
            addLeaf(root->right, ans);
        }
    }
    void addRight(TreeNode* root, vector<int>& ans){
        TreeNode* curr= root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->val);
            }
            if(curr->right)
                curr = curr->right;
            else 
                curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        if(!isLeaf(root))
            ans.push_back(root->val);
        addLeft(root, ans);
        addLeaf(root, ans);
        addRight(root, ans);
        return ans;
    }
};





int main(){

    return 0;
}