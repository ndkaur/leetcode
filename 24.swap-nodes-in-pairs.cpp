/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
// X -> 1 -> 2 ->3  ->4
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp=new ListNode(-1);
        temp->next=head;
        ListNode *curr=head;
        ListNode* prev = temp;
        while(curr && curr->next){
            ListNode *nx=curr->next->next;
            curr->next->next=curr;
            
            prev->next=curr->next;
            curr->next=nx;

            prev=curr;
            curr=curr->next;
            }
        return temp->next;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        dummy->next= head;
        ListNode* prev = dummy;
        while(prev->next && prev->next->next){
            ListNode* curr= prev->next;
            ListNode* forward = curr->next;
            ListNode* temp= forward->next;

            prev->next= forward;
            curr->next= temp;
            forward->next= curr;

            prev= curr;
        }
        return dummy->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4};
    ListNode *head=createList(a);
    ListNode *out=sol.swapPairs(head);
    printList(head);
    return 0;
}