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
    bool checkTree(TreeNode* root) {
        if(!root) return false;
        int left= root->left->val;
        int right= root->right->val;
        if(root->val== left+ right)
            return true;
        return false;
    }
};

int main(){

    return 0;
}