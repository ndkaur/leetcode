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
    bool evaluateTree(TreeNode* root) {
        if(root->val ==1)  return true;
        if(root->val == 0)  return false;
        if(root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
        if(root->val == 3)
            return evaluateTree(root->left) && evaluateTree(root->right);
        return true;
    }
};


int main(){

    return 0;
}