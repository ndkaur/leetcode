/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *curr=head;
        ListNode *temp;

        while(curr){
            if(curr->next && curr->next->val<curr->val){
                while(prev->next && prev->next->val<curr->next->val){
                    prev=prev->next;
                }
                temp=prev->next;
                prev->next=curr->next;
                curr->next=curr->next->next;
                prev->next->next=temp;
                prev=dummy;
            }
            else {
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={8,7,6,95,23,5};
    ListNode *head=createList(a);
    ListNode *ans=sol.insertionSortList(head);
    printList(ans);
    return 0;
}