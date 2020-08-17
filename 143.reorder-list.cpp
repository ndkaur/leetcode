/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if(!head || !head->next)  
            return ;

        ListNode *curr=head;
        ListNode *mid= findMid(head);
        // break list in two parts start and end . mid is center
        while(curr->next!=mid){
            curr=curr->next;
        }
        curr->next=NULL; // list break

        ListNode *start=head;
        ListNode *end=reverseList(mid);

        ListNode *attach=new ListNode(0);
        ListNode *help=attach;

        while(start){
            help->next=start;
            start=start->next;
            help=help->next;

            help->next=end;
            end=end->next;
            help=help->next;
        }
        head=attach->next;
    }
    ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    };

    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next=curr->next;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
       return prev;
    }

};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4};
    ListNode *head=createList(a);
    sol.reorderList(head);
    printList(head);
    return 0;
}