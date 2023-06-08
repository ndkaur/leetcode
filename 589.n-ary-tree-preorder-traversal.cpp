/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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

class Solution {
public:
    vector<int> preorder(Node* root) {
        // preorder = root , left, right
        // ie root , children
        if(!root) return {};
        vector<int> ans;
        stack<Node*> stk;
        stk.push(root);
        while(stk.size()){
            root = stk.top();
            stk.pop();
            // root
            ans.push_back(root->val);
            // children
            //1 2 3 4 , 4 2 so we need to visit them from backwards
            int sz= root->children.size();
            for(int i=sz-1; i>=0; i--){
                if(root->children[i])
                    stk.push(root->children[i]);
            }
        }
        return ans;
    }
};


// forward for loop then ans = 1 4 2 3 6 5 
// root of 1 are 3,2,4 but 
// in stack they will pushed in order 3 2 4 and 4 will be poped first 
// but if we see 4 is kind of like right child 
// but in preorder we need left first so reverse for loop 




// @lc code=end


int main(){

    return 0;
}