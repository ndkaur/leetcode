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