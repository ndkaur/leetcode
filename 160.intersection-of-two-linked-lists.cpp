/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return NULL;
        if(!headB)  return NULL;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b){
            if(a){
                a=a->next;
            }
            else 
                a=headB;
            if(b){
                b=b->next;
            }
            else 
                b=headA;
        }
        deb(a->val);
        return a;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> one={1,9,1,2,4};
    vector<int> two={3,2,4};
    ListNode *headA=createList(one);
    ListNode *headB=createList(two);
    ListNode *ans;
    ans= sol.getIntersectionNode(headA,headB);
    return 0;
}