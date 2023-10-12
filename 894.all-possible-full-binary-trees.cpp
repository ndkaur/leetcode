/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */
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


// full binary tree can only have odd number of roots on its both left and right side 
// cause the rule is either the root can have 0 children or 2 children 
// and suppose n = 5   1 2 3 4 5  we will choose the nodes one by one to make them root 
// but not all nodes can become the root cause each root must have odd number of roots remaining on its both sides
// 1 2 3 4 5   choose 1 left side 0 children, right side  4 children even not possible 
// choose 2 -> left side 1 child , right side 3 child possible 
// choose 3 -> lft side 2 children , right side 2 child  not possible 
// so our loop will go at pace of 2 i+=2


//n=1 one possible 
//  n=2 not possible  as full bt has no or 2 children
// n=3 possible 
// n=4 not possible 
//  0 1 2 3 4 5 6
//  1 2 3 4 5 6 7 -> value of n 
//  n y n y n y n 
// so observation here is that our index at odd are possible so we will skip even indexes 
//  idx =3 , left side (n=3) , right side (n=3)
class Solution0 {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
            return {};
        vector<TreeNode*> ans;

        if(n==1){// base case 
            TreeNode* newTree = new TreeNode(0);
            ans.push_back(newTree);
            return ans;
        }

        for(int i=1; i<n; i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1); 
            // suppose left = {fbt1, fbt2, fbt3}
            // suppose right = {fbt4, fbt5, fbt6}
            // then combination will be 
            //  fbt1->root->fbt4 , or  fbt1->root->fbt5, or fbt3->root->fbt6
            // fbt2->root->fbt4 , or fbt2->root->fbt5
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root= new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};  

// meomization 
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
            return {};
        unordered_map<int, vector<TreeNode*>> mp;
        vector<TreeNode*> ans;

        if(n==1){// base case 
            TreeNode* newTree = new TreeNode(0);
            ans.push_back(newTree);
            return ans;
        }
        
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }

        for(int i=1; i<n; i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1); 
            // suppose left = {fbt1, fbt2, fbt3}
            // suppose right = {fbt4, fbt5, fbt6}
            // then combination will be 
            //  fbt1->root->fbt4 , or  fbt1->root->fbt5, or fbt3->root->fbt6
            // fbt2->root->fbt4 , or fbt2->root->fbt5
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root= new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }
};  

// when i =1 then left side will get n=1 and right will get n=5 ILliiI

                    n = 7
        i=1     i=2     i=3     i=4    i=5    i=6
        yes     no      yes     no     yes    no 
      (1)  (5)        (3)    (3)       (5)
          (1) (3)     (1) (1)  (1) (1)   i=1      i=3 
         {0}         {0}    {0}       (1) (3)    (1)  (1)
                                    {0}  i=3     {0}  {0}
                                        (1) (1)
                                        {0}  {0}

// @lc code=end

int main(){
    
    return 0;
}