/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */
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


class Solution0 {
public:
    void dfs(TreeNode* root, unordered_map<int,int> mp, int& cnt ){
        if(!root)
            return;
        mp[root->val]++;

        if(!root->left && !root->right){
            int single = 0;
            for(auto itr:mp){
                if(itr.second%2==1){
                    single++;
                }
            }
            if(single<=1)
                cnt++;
        }
        
        if(root->left)
            dfs(root->left, mp, cnt);
        if(root->right)
            dfs(root->right, mp, cnt);
       
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)
            return 0;
        unordered_map<int,int> mp;
        int cnt = 0;
        dfs(root, mp, cnt);
        return cnt;
    }
};


class Solution {
public:
    void preorder(TreeNode* root, int path, int& cnt){
        if(!root)
            return;
        
        path = path ^ (1<<root->val);
       // we reached the child node
        if(!root->left && !root->right){
            if(__builtin_popcount(path)<=1)
                cnt++;
            return;
        }
        preorder(root->left, path, cnt);
        preorder(root->right, path, cnt);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        preorder(root,0, cnt);
        return cnt;
    }
};

// create the path as we move ahead in traversal
        // eg -> root->val = 2 so set the bit onn at idx =2  100 using 1<<root->Val
        // now to create a mask we want to preserve the same order as 100 we will use xor 
        // next left node = 3 , mask will be -> set the bit on at 3rd index and preserve the previous states also , 1100 , so to make 1100 from 0100 
        // 2->  0 1 0 0
        // 3->  1 0 0 0
        // ans  1 1 0 0  <- to reach this we can use zor  


                // now as we know a plaindrome can only be made when in odd len only one number occurs 1 time and all other numbers occcur even times
                // so it the bit is 1 ie the number occur 1 time 
                // if the bit is 0 ie the number occur even time  
                // and we want either all numbers occcur even times or only 1 nummber occcur 1 time
                // eg:- (2->3->3) 0100 no of set bits =1 so cnt++ 
                //  eg:- (2->3->1) 1110  no of set bits = 3 , so no palindrome 
                //  to check set bits we have few methods 
                // 1. while(n){cnt+= n%2; n=n/2;}
                //  2. use internal __builtin_popcount(int number); 
                // 3. n & (n-1) if all 0 then cnt++;



// @lc code=end


int main(){

    return 0;
}