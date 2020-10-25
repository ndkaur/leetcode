 /*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;
        
        while (getline (ss, item, '-')) 
            root = insert(root, stoi(item));

        return root;
    }
    
private:
    string encode(TreeNode* root) {
        if (!root)
            return "";
        return to_string(root->val) + "-" + encode(root->left)+encode(root->right);
    }
    
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
			TreeNode* temp=new TreeNode(val);
			return temp;
		}
    
		if (val<=root->val)
			root->left=insert(root->left,val);
    
		else
			root->right=insert(root->right,val);
    
		return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end


int main(){

    return 0;
}