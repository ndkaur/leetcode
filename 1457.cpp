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

class Solution {
    int count=0;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count;
    }
    void preorder(TreeNode *root, int times){
        if(root != NULL){
            //no of occurence 
            times = times ^ (1<<root->val);
            // if pseudo or not 
            if(root->left ==NULL && root->right == NULL){
                // frequency as 1 of at most one digit 
                if(times & (times-1) ==0)
                    count++;
            }
            preorder(root->left , times);
            preorder(root->right,times);
        }
    }
};


int main(){
    
    return 0;
}