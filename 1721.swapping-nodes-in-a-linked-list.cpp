/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

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
    int len(ListNode* head){
        int l=0;
        ListNode* tempo= head;
        while(tempo!= NULL){
            l++;
            tempo= tempo->next;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int l=len(head);
        ListNode* one = head;
        ListNode* two=head;
        for(int i=1;i!=k;i++){
            one= one->next;
        }
        for(int j=1;j<l-k+1;j++){
            two = two->next;
        }
        int temp= one->val;
        one->val= two->val;
        two->val= temp;
        return head;
    }
};


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* first = head;
       ListNode* last= head;
       ListNode* curr= head;
       for(int i=1;i<k && curr!=NULL;i++){
           curr= curr->next;
           first= first->next;
       }
       while(curr->next!=NULL){
           last= last->next;
           curr= curr->next;
       }
       int temp = first->val;
       first->val= last->val;
       last->val = temp;
       return head;
    }
};
// @lc code=end

