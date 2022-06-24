/*
 * @lc app=leetcode id=1932 lang=cpp
 *
 * [1932] Merge BSTs to Create Single BST
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
class Solution {
public:
    bool isValid(TreeNode* root){
        return valid(root, INT_MIN, INT_MAX);
    }

    bool valid(TreeNode* root, long minVal, long maxVal){
        if(root==NULL)
            return true;
        // min<root<max  // opposite min > root > max
        if(root->val >= maxVal || root->val <= minVal)
            return false;
        return valid(root->left,minVal,root->val) && valid(root->right, root->val, maxVal);
    }

    void make_tree(TreeNode* &root, unordered_map<int, TreeNode*>& mp){
        if(!root) return;
        if(root->left){
            if(mp[root->left->val]){
                root->left= mp[root->left->val];
                mp[root->left->val]=NULL;
            }
        }
        if(root->right){
            if(mp[root->right->val]){
                root->right = mp[root->right->val];
                mp[root->right->val] =NULL;
            }
        }
        make_tree(root->left,mp);
        make_tree(root->right, mp);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // map to store {root, freq} -> {1,1} {2,2} {3,1} {4,1} {5,2}
        unordered_map<int, int> nodes;
        for(auto x:trees){
            nodes[x->val]++;
            if(x->left){
                nodes[x->left->val]++;
            }
            if(x->right){
                nodes[x->right->val]++;
            }
        }

        TreeNode* curr=NULL; // to find which will become the main tree node root
        //  the root whose freq is only 1 times 
        for(auto x:trees){
            if(nodes[x->val]==1){
                if(curr!=NULL)  // only one node can be the main tree node
                    return NULL;
                curr=x;
            }
        }

        // map to store node val corresponding to each node
        // store {root, root->val} -> {1,1} {2,2} {3,3} {4,4} {5,5}
        unordered_map<int,TreeNode*> mp; 
        for(auto x:trees){
            mp[x->val]=x;
        }

        make_tree(curr, mp);
        //  check if all subtres are included in the main btree formed 
        int count=0;
        //  if in map the root->val is zero for all except for the main root node then 
        for(auto x:mp){
            if(x.second!=NULL) 
                count++;
        }
        if(count>1)  // not all included
            return NULL;

        //  check for bt to be a valid bst
        if(isValid(curr))
            return curr;
        return NULL;
    }
};


class Solution {
public:
//  store {root,root->val} ->{1,1} {2,2}...
    unordered_map<int,TreeNode*> rootMap;

    bool valid(TreeNode* root, long left, long right){
        if(root==NULL)
            return true;
        // min< root< max
        int res= root->val > left &&  root->val < right;
        res= res && valid(root->left,left,root->val) && valid(root->right, root->val,right);
        return res;
    }

    bool isValid(TreeNode* root){
        return valid(root, LONG_MIN, LONG_MAX);
    }

    TreeNode* mergeAll(TreeNode* root){
        TreeNode* res= rootMap.count(root->val) ? rootMap[root->val] : root;
        rootMap.erase(root->val);
        if(res->left) 
            root->left = mergeAll(res->left);
        if(res->right)
            root->right= mergeAll(res->right);
        return res;
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
        unordered_set<int> st; // stores all the leafes values {1,2,5,4}
        
        for(auto x:trees){
            rootMap[x->val]= x;
            if(x->left) 
                st.insert(x->left->val); // store the left child
            if(x->right)
                st.insert(x->right->val);
        }

        TreeNode* root; // this will be the main root of bst
        for(auto x:trees){
            if(!st.count(x->val)){ // the root node doesnt exist in set of leaves
                root=x;
                break;
            }
        }

        mergeAll(root);
        //  after each pass we earse that node from the rootMap so the size must be empty
        return isValid(root) && (rootMap.size()==0) ? root:NULL;
    }
};

// @lc code=end


int main(){

    return 0;
}