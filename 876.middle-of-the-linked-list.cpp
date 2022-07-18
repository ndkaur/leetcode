/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        if(head=NULL)
            return 0;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp= head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp= temp->next;
        }
        int half= n/2;
        temp= head;
        while(half--){
            temp= temp->next;
        }
        return temp;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vi a={1,2,3,4,5,6};
    ListNode *head= createList(a);
    ListNode *ans=sol.middleNode(head);
    cout<<ans->val;
    return 0;
}