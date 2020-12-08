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

// class Solution {
//     int count=0;
// public:
//     int goodNodes(TreeNode* root) {
//         giveCount(root,INT_MIN);
//         return count;
//     }
//     void giveCount(TreeNode* root, int  mx){
//         if(!root) return ;
//         //mx=0 in the begining 
//         if(root->val >= mx){
//             count++;
//             mx=root->val;
//         }
//         giveCount(root->left,mx);
//         giveCount(root->right, mx);
//     }
// };

class Solution {
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        int m = INT_MIN;
        q.push({root,m});
        int count=0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode * node=curr.first;
            int num=curr.second;
            if(node->val >= num){
                count++;
            }
            m = max(node->val,num);
            if(node->left)
                q.push({node->left,m});
            if(node->right)
                q.push({node->right,m});
        }
        return count;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    }
    return 0;
}