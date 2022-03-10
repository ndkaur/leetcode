/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(0);
		ListNode *ans = dummy;
		int carry = 0;
		int a(0),b(0),sum(0);
		while(l1 || l2 || carry){
			a = l1 ? l1->val : 0;
			b = l2 ? l2->val : 0;
			sum = a+b + carry;
			carry = sum/10; // extra number to be forwaded
			sum = sum%10; // remiander
			ans->next = new ListNode(sum);
			ans = ans->next;
            // if l1 or l2 is still present
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return dummy->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* temp= dummy;
        ListNode* p=l1;
        ListNode* q= l2;
        int carry=0;
        while(p || q){
            int x= p? p->val:0;
            int y= q ? q->val:0;
            int sum= carry+x+y;
            carry= sum/10;
            temp->next= new ListNode(sum%10);
            temp= temp->next;
            if(p) p= p->next;
            if(q) q= q->next;
        }
        if(carry>0){
            temp->next= new ListNode(carry);
        }
        return dummy->next;
    }
};
// @lc code=end


// list is reversed so the ans may varry in int main 
// code is correct 
int main(){
    Solution sol;
    vector<int> a={2,4,3};
    vector<int> b={5,6,7};
    ListNode *l1=createList(a);
    ListNode *l2=createList(b);
    ListNode *ans=sol.addTwoNumbers(l1,l2);
    printList(ans);
    return 0;
}