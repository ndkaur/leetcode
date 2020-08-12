/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *prev=new ListNode(0);
        prev->next=head;
        ListNode *temp=prev;
        while(temp){
            int sum=0;
            while(head){
                sum=sum+head->val;
                if(sum==0)
                    temp->next=head->next;
                head=head->next;
            }
            temp=temp->next;
            if(temp)
                head=temp->next;
        }
        
        return prev->next;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,-3,3,1};
    ListNode *head= createList(a);
    ListNode *ans=sol.removeZeroSumSublists(head);
    printList(ans);
    return 0;
}