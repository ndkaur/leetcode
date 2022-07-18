/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* curr= head;
        ListNode* nxt= head->next;
        ListNode* prev=NULL;
        while(curr!=NULL){
            curr->next= prev;
            prev= curr;
            curr= nxt;
            if(nxt!=NULL)
                nxt= nxt->next;
        }
        return prev;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* curr= head;
        ListNode* nxt;
        ListNode* prev=NULL;
        while(curr!=NULL){
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        return prev;
    }
};

//  recursive 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* newhead= reverseList(head->next);
        head->next->next= head;
        head->next=NULL;
        return newhead;
    }
};
// @lc code=end

int main(){
    Solution sol;

    return 0;
}