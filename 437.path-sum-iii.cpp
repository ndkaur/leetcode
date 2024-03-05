/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

class Solution { //O(N^2)
public:
    int ans=0; // we need the same count for the root->left and root->right so declare it publically 
    void dfs(TreeNode* root, long long sum){
        if(!root) return;
        if(root->val==sum) 
            ans++;
        dfs(root->left, sum-root->val);
        dfs(root->right, sum-root->val);
    }

    int pathSum(TreeNode* root, int sum) {
        if(root){
            dfs(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;
    }
};

class Solution { //O(N)
public:
    int pathSum(TreeNode* root, int target) {
        unordered_map<long long,int> mp;
        mp[0]=1;
        return solve(root, target, 0, mp);
    }
    int solve(TreeNode* root, int target, long long curr, unordered_map<long long,int>& mp){
        if(!root)
            return 0;
        curr += root->val;
        // target = 8 , curr = 2 find if in map 8-2 = 6 exist or not 
        int cnt = mp[curr-target];
        mp[curr]++;

        int left = solve(root->left, target, curr, mp);
        int right = solve(root->right,target, curr, mp);
        // backtrack
        mp[curr]--;
        curr -= root->val;
        return cnt+left+right;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long ,int> mp;
        int cnt = 0;
        f(root, targetSum, 0, cnt, mp);
        return cnt;
    }
    void f(TreeNode* root, int target, long long curr, int& cnt, unordered_map<long long ,int>& mp){
        if(!root)
            return ;

        curr += root->val;

        if(mp.find(-target+curr)!= mp.end()){
            cnt += mp[-target+curr];
        }

        if(curr==target)
            cnt+=1;
            
        mp[curr]++;

        f(root->left, target, curr, cnt, mp);
        f(root->right, target, curr, cnt, mp);

        mp[curr]--;
        curr -= root->val;
    }
};


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        return f(root, targetSum) + pathSum(root->left, targetSum) +pathSum(root->right, targetSum);
    }
    int f(TreeNode* root, long long target){
        if(!root || target<-1999999000)
            return 0;
        int cnt =0;
        if(root->val==target){
            cnt++;
        }
        cnt += f(root->left, target-root->val);
        cnt += f(root->right, target-root->val);
        return cnt;
    }
};

// @lc code=end


int main(){

    return 0;
}