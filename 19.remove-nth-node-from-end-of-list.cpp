/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *a=head;
        int lenght=0;
        while(a!=NULL){
            lenght++;
            a=a->next;
        }
        lenght=lenght-n;
        a=dummy;
        while(lenght>0){
            lenght--;
            a=a->next;
        }
        a->next=a->next->next;
        return dummy->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4,5};
    int n=2;
    ListNode *head=createList(a);
    ListNode *ans=sol.removeNthFromEnd(head,n);
    printList(ans);
    return 0;
}