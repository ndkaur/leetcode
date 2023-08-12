/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right)
            return head;
        ListNode* curr = head;

        ListNode* start =NULL;
        ListNode* end = NULL;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        int cnt=1;
        while(cnt<left){
            prev = curr;
            curr = curr->next;
            cnt++;
        } 
        // now prev points to one index behind the left
        // and temp poiniting on left
        start = curr;
        // reverse till right
        // 1->2->3->4->5   prev = 1, curr = 2
        while(cnt<= right){
            nxt = curr->next;
            curr->next = end; // null ptr 
            end = curr;
            curr = nxt;
            cnt++;
        }
        // after reverse 4->3->2->NULL but also start = 2
        // now joing the curr node with original list
        start->next = curr;
        if(prev!=NULL){ // if left is not a starting node then prev will have some value
            prev->next = end;
            return head;
        }
        return end;
    }
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for(int i = 0; i < left - 1; i++)    prev = prev->next;
        ListNode *curr = prev->next;

        for(int i = 0; i < right - left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;

        
        
    }
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *curr= head;
        ListNode *prev=NULL;
        ListNode *temp= NULL;
        ListNode *start=NULL;
        ListNode *end=NULL;
        int i=0;
        for(;i<m;i++){
            if(i==m-1){
                start=prev;
            }
            prev=curr;
            curr=curr->next;
        }
        end=prev; // prev is the original end after reversing
        
        for(;i<n;i++){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        end->next=curr;
        if(start) 
            start->next=prev;
        else 
            head=prev;
       
        return head;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4,5};
    int m=2,n=4;
    ListNode *head=createList(a);
    ListNode *ans=sol.reverseBetween(head,m,n);
    printList(ans);
    return 0;
}