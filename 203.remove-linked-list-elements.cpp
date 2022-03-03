/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int value) {
        if(!head)
            return head;
        ListNode *prev=nullptr,*curr=head;
        while(curr){
            if(curr->val==value){
                if(!prev)
                    head=curr->next;
                else 
                    prev->next=curr->next;
            }
            else 
                prev=curr;
            
            curr=curr->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {
        if(head==NULL) return NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* tail= dummy;
        while(tail && tail->next){
            if(tail->next->val== value){
                ListNode* temp = tail->next;
                tail->next= tail->next->next;
                delete temp;
            }
            else
                tail= tail->next;
        }
        return dummy->next;
    }
};

//  recursion 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        head->next= removeElements(head->next,val);
        if(head->val==val){
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        else
            return head;
    }
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        head->next= removeElements(head->next,val);
        return head->val==val ? head->next: head;
    }
};
// @lc code=end


int main(){

    return 0;
}