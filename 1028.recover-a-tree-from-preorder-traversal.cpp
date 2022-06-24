/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  inorder to tree form 
//  dash means level 
class Solution { // time -> O(traversal size) , space-> O(n)
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stk;
        //  count the level parallel to each level 
        for(int i=0;i<traversal.size();){ // to traverse on the string 
            int level=0;
            while(traversal[i]=='-'){
                ++level;
                ++i;
            }
            //  find the digit from the string .. can be tens place or 100 th place digit so 
            int start=i;
            while(isdigit(traversal[i])){
                ++i;
            }
            int val = stoi(traversal.substr(start, i-start+1));
            TreeNode* temp = new TreeNode(val); 
            if(stk.empty()){
                stk.push(temp);
                continue;
            }
            //  finding where to insert the node at the particular level 
            // when stk. size and level become equal that is where node will be placed  
            while(stk.size()>level) stk.pop();
            if(stk.top()->left) stk.top()->right =temp;
            else stk.top()->left = temp;
            stk.push(temp);   
        }
        //  poping out all except the starting node of tree
        while(stk.size()>1) stk.pop();
        return stk.top();
    }
};

//             val  level 
//             1     0
//             401   1
//             349   2 
//             90    3
//             88    2
// @lc code=end


int main(){
    Solution sol;
    string traversal = "1-2--3--4-5--6--7";
    TreeNode ans = sol.recoverFromPreorder(traversal);

    return 0;
}