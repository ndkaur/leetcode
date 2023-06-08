/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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

class Solution {
public:
    vector<int> postorder(Node* root) {
        // left right root 
        // but we need root first sot hat we can visit its children 
        // so if we reverse the order root right left 
        vector<int> ans;
        if(!root) return {};
        stack<Node*> stk;
        stk.push(root);
        while(stk.size()){
            root = stk.top();
            stk.pop();
            // root
            ans.push_back(root->val);
            // right left ie children
            int sz = root->children.size();
            for(int i=0; i<sz; i++){
                if(root->children[i])
                    stk.push(root->children[i]);
            }
        }
        // reverse the ans array 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}