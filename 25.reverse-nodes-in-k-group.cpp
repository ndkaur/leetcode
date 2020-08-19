/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverse(ListNode *head){
        ListNode *curr;
        ListNode *prev;
        ListNode *temp;
        curr=head;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy =new ListNode(-1);
        ListNode *prev=dummy;
        prev->next=head;
        ListNode *curr;
        ListNode *nextnode;
        while(prev){
            curr=prev;
            for(int i=0;i<k;i++){
                if(curr){
                    curr=curr->next;
                }
            }
            if(!curr) break;
            else
                nextnode=curr->next;
            
            curr->next=NULL;
            prev->next= reverse(prev->next);

            for(int i=0;i<k;i++){
                prev=prev->next;
            }
            prev->next=nextnode;
        }
        return dummy->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4,5};
    ListNode *head=createList(a);
    int k=3;
    ListNode *ans=sol.reverseKGroup(head,k);
    printList(ans);
    return 0;
}