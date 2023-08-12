/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            if(curr->next && curr->val == curr->next->val){
                while(curr->next && curr->val==curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else {
               prev = curr;
            }
            curr= curr->next;
        }
        return dummy->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,3,4,4,5};
    ListNode *head=createList(a);
    ListNode *ans= sol.deleteDuplicates(head);
    printList(ans);
    return 0;
}