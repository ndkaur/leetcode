/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        ListNode* curr= head;
        while(curr!=NULL){
            vec.push_back(curr->val);
            curr= curr->next;
        }
        return arrayToBST(vec);
    }
    TreeNode* arrayToBST(vector<int>& nums){
        if(nums.size()==0)
            return NULL;
        return convertToBST(nums,0,nums.size());
    }
    TreeNode* convertToBST(vector<int>& nums, int l, int r){
        if(l>=r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left= convertToBST(nums,l,mid);
        root->right= convertToBST(nums,mid+1, r);
        return root;
    }
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        ListNode* slow= head;
        ListNode* fast= head;
        ListNode* mid= NULL;
        while(fast && fast->next){
            mid= slow;
            slow= slow->next;
            fast= fast->next->next;
        }
        mid->next= NULL;
        TreeNode* root= new TreeNode(slow->val);
        root->left= sortedListToBST(head);
        root->right= sortedListToBST(slow->next);
        return root;
    }
};
// @lc code=end


int main(){

    return 0;
}