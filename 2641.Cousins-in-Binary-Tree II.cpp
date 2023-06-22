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

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return NULL;
        // root val always be 0 
        root->val =0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<TreeNode*> arr;
            int sum =0;
            // at the end of this loop
            // we will have sum of all nodes at that level
            while(n--){
                auto node= q.front();
                q.pop();
                arr.push_back(node);
                if(node->left){
                    q.push(node->left);
                    sum += node->left->val; 
                }
                if(node->right){
                    q.push(node->right);
                    sum += node->right->val;
                }
            }
            // sum will come from other node 
            // so when on left side we want only sum of right side
            for(auto node:arr){
                int temp = sum;
                // sum from nodes with same parents is removed
                if(node->left) 
                    temp -= node->left->val;
                if(node->right)
                    temp -= node->right->val;
                // now the remaining sum will be the cousin sum 
                if(node->left)
                    node->left->val= temp;
                if(node->right)
                    node->right->val = temp;
            }
        }
        return root;
    }
};






int main(){

    return 0;
}