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

class Solution0 {
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        int mx=INT_MIN;
        dfs(root,count,mx);
        return count;
    }
    void dfs(TreeNode* curr, int& count, int mx){
        if(!curr)
            return;
        if(curr->val >= mx){
            count++;
            mx= curr->val;
        }
        dfs(curr->left, count,mx);
        dfs(curr->right, count,mx);
    }
};


        // {node, mx val till then }
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        int mx=INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root, mx});
        while(q.size()){
            auto curr= q.front();
            q.pop();
            
            TreeNode* cnode= curr.first;
            int cval = curr.second;
            
            if(cnode->val >= cval)
                count++;
            mx= max(cnode->val, cval);
            if(cnode->left)
                q.push({cnode->left, mx});
            if(cnode->right)
                q.push({cnode->right, mx});
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