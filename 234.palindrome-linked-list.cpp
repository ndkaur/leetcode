/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
class Solution0 {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        stack<int> stk;
        
        while(temp){
            stk.push(temp->val);
            temp=temp->next;
        }

        while(head){
            if(head->val != stk.top())
                return false;
            stk.pop();
            head=head->next; 
        }
        return true;
    }
};

// find the mid element then reverse the list next to mid 
//  take two ptrs one on head one on element next to mid 
// then again revrse the list to make it same as original

class Solution {  // O(n)
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reversList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reversList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};



class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL) 
            return head;
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* nxt= head->next;
        while(curr!=NULL){
            curr->next= prev;
            prev= curr;
            curr= nxt;
            if(nxt!=NULL)
                nxt= nxt->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        // finding the one position behind the mid 
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        // reverse the half list from mid till end 
        slow->next= reverseList(slow->next);
        // compare both the lisitng with two ptrs 
        ListNode* start= head;
        ListNode* mid = slow->next;
        while(mid!=NULL){
            if(mid->val!=start->val)
                return false;
            start= start->next;
            mid= mid->next;
        }
        // to again restore the orignal order of the list 
        slow->next= reverseList(slow->next);
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={};
    ListNode *head= createList(a);
    bool ans=sol.isPalindrome(head);
    cout<<ans;
    return 0;
}