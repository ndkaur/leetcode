/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *curr=head;
        ListNode *prev;
        ListNode *curr2;
        if(k==0 || !head) return head;
        //lenght of list
        int len=0;
        while(curr){
            curr=curr->next;
            len++;
        }
        if(len==1 || k%len==0 ) return head;
        // 5-2=3 we have to reach 3
        curr=head;
        k=k%len;
        int sz=len-k;
        while(sz){
            prev=curr;
            curr=curr->next;
            sz--;
        }
        prev->next=NULL;
        curr2=curr;
        while(curr2->next){
            curr2=curr2->next;
        }
        curr2->next=head;
        head=curr;
        
        return head;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={0,1,2};
    ListNode *head=createList(a);
    int k=4;
    ListNode *ans=sol.rotateRight(head,k);
    printList(ans);
    return 0;
}