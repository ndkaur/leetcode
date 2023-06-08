/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */
#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout << x << endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
// #include "LinkedList.h"

void print(vi &out)
{
    for (auto x : out)
        cout << x << " ";
    cout << endl;
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
class Solution
{
public:
    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }
    int dfs(TreeNode *root, int curr)
    {
        if (!root)
            return 0;
        // converting binary to decimal
        curr = (curr << 1) | root->val;
        if (!root->left && !root->right)
            return curr;
        return dfs(root->left, curr) + dfs(root->right, curr);
    }
};

class Solution
{
public:
    int sumRootToLeaf(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        // node , curr num till there
        stack<pair<TreeNode *, int>> st;
        st.push({root, 0});
        while (!st.empty())
        {
            auto curpair = st.top();
            st.pop();
            TreeNode *curnode = curpair.first;
            int curval = curpair.second;

            curval = curval * 2 + curnode->val;
            // reached the leaf node then add the num formed to the ans
            if (!curnode->left && !curnode->right)
                ans += curval;
            if (curnode->left)
                st.push({curnode->left, curval});
            if (curnode->right)
                st.push({curnode->right, curval});
        }
        return ans;
    }
};

// @lc code=end

int main()
{

    return 0;
}