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
    TreeNode* findParent(TreeNode* root, map<TreeNode*,TreeNode*>& mp, int& start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(q.size()){
            auto node= q.front();
            if(node->val==start)
                res= node;
            q.pop();
            if(node->left){
                mp[node->left]= node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]= node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findCnt(TreeNode* root, map<TreeNode*, TreeNode*>& mp, TreeNode* target){
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(target);

        map<TreeNode*, int> visited;
        visited[target]=1;

        while(q.size()){
            int sz = q.size();
            int flag = 0;
            for(int i=0; i<sz; i++){
                auto node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    flag =1;
                    q.push(node->left);
                    visited[node->left]=1;
                }
                if(node->right && !visited[node->right]){
                    flag=1;
                    q.push(node->right);
                    visited[node->right]=1;
                }
                if(mp[node] && !visited[mp[node]]){
                    flag=1;
                    q.push(mp[node]);
                    visited[mp[node]] =1;
                }
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)
            return 0;
        map<TreeNode*,TreeNode*> mp;
        TreeNode* target = findParent(root, mp, start);
        int cnt = findCnt(root, mp, target);
        return cnt;
    }
};



int main(){

    return 0;
}