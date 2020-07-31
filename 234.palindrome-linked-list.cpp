/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        stack<int> stk;
        
        while(temp){
            stk.push(temp->val);
            temp=temp->next;
        }

        while(head){
            if(head->val != stk.top())
                return false;
            stk.pop();
            head=head->next; 
        }
        return true;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={};
    ListNode *head= createList(a);
    bool ans=sol.isPalindrome(head);
    cout<<ans;
    return 0;
}