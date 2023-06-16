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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> arr;
        while(q.size()){
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                auto node = q.front();
                q.pop();
                if(level%2){ // odd
                    // replacing with the reverse required position
                    node->val = arr[n-i-1];
                }
                if(node->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            level++;
            arr = temp;
        }
        return root;
    }
};

int main(){

    return 0;
}