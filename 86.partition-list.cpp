/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before_head= new ListNode(0);
        ListNode *before=before_head;

        ListNode *after_head=new ListNode(0);
        ListNode *after=after_head;

        //comparing
        while(head){
            if(head->val < x){
                before->next=head;
                before=before->next;
            }
            else {
                after->next=head;
                after=after->next;
            }
            head=head->next;
        }
        // joinig both lists
        after->next=NULL;
        before->next=after_head->next;

        return before_head->next;
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> a={1,4,3,2,5,2};
    ListNode *head=createList(a);
    int x=3;
    ListNode *ans=sol.partition(head,x);
    printList(ans);
    return 0;
}
