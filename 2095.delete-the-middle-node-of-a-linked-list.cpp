/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL )
            return NULL;
        if(head==NULL) return NULL;
        
        ListNode* slow= head;
        ListNode* fast = head;
        ListNode* temp=head;
        while(fast && fast->next){
            temp = slow;
            slow= slow->next;
            fast= fast->next->next;
        }
        temp->next= slow->next;
        return head;
    }
};


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return NULL;
        if(head->next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast= fast->next->next;
            slow= slow->next;
        }
        ListNode* del = head;
        while(del->next != slow){
            del=  del->next;
        }
        
        del->next = del->next->next;
        return head;
    }
};


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return NULL;
        if(head->next == NULL)
            return NULL;
        ListNode* slow= head;
        ListNode*fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// @lc code=end


int main(){

    return 0;
}