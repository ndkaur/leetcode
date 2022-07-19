/*
 * @lc app=leetcode id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
 */
#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* h1= list1;
        ListNode* h2= list1;
        while(b--){
            h2= h2->next;
        }
        while(a!=1){
            h1= h1->next;
            a--;
        }
        h1->next=list2;
        while(h1->next!=NULL){
            h1= h1->next;
        }
        h1->next= h2->next;
        return list1;
    }
};


class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        int idx1=1;
        // we want to place our ptr just one idx behind the a 
        while(idx1<a){
            temp1= temp1->next;
            idx1++;
        }
        
        ListNode* temp2= list1;
        int idx2=1;
        while(idx2<=b){
            temp2= temp2->next;
            idx2++;
        }
        
        ListNode* temp3= list2;
        // take pt3 to the end of list2
        while(temp3->next!=NULL){
            temp3= temp3->next;
        }
        
        temp1->next= list2;
        temp3->next= temp2->next;
        
        return list1;
    }
};


class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2= list1;
        // a-1 cause we have to attach prev of a with new list 
        for(int i=0;i<a-1;i++)
            temp1= temp1->next;
        // go till less than b cause have to atatch b->ext with last node of list2 
        for(int i=0;i<b;i++)
            temp2= temp2->next;
        
        //  attach with list2
        temp1->next= list2;
        while(list2->next!=NULL)
            list2= list2->next;
        // list2 idx reached the end of list 2 
        // attach with the list1 
        list2->next= temp2->next;
        return list1;
    }
};
// @lc code=end


int main(){

    return 0;
}