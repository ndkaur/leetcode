/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *extra = new ListNode(INT_MIN);
        ListNode *l3=extra;

        while(l1 && l2){
            if(l1->val<l2->val){
                l3->next=l1;
                l1=l1->next;
            }
            else{
                l3->next=l2;
                l2=l2->next;
            }
            l3=l3->next;
        }
        if(l1)
            l3->next=l1;
        else 
            l3->next=l2;
        
        return extra->next;
    }
};

//  recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val){
            l1->next= mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next= mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};

// @lc code=end
int main() {
    
    return 0;
}