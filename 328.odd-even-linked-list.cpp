/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *odd=head;
        ListNode *even =head->next;
        ListNode *evenHead =even;
        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next= evenHead;
        return head;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vi a={1,2,3,4,5,6,7,8};
    ListNode *head= createList(a);
    ListNode *ans= sol.oddEvenList(head);
    printList(ans);
    return 0;
}
