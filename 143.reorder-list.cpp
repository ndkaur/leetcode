/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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

class Solution { // O(N)   O(N)
public:
    void reorderList(ListNode* head) {
        if(!head) return NULL;
        //use stack to add the last ele 
        stack<ListNode*> stk;
        ListNode* curr= head;
        // filling the stack
        while(curr!=NULL){
            stk.push(curr);
            curr= curr->next;
        }
        // we can only take half of the ele from stack and use them 
        int n = stk.size();
        if(n<=2) return; 
        ListNode* nxt;
        for(int i=0;i<n/2;i++){ // n= 5 can take till 5/2 =2  i<2 -> 0,1 idx -> 5 ans 4 val 
            nxt = curr->next;
            curr->next = stk.top(); // 1->5  curr=1
            stk.pop(); 
            curr= curr->next;  // curr= 5
            curr-> next=  nxt; // 1->5->2 ->3->4  // curr= 5 
            curr= curr->next;   // curr= 2
            // loop for i=1 will start after this and perform same steps 
        }  
        curr-> next= NULL;
    }
};

// observation -> only second half of the string is majorly used 
// 1-> 2 ->3 ->4 -> 5
// 1->5->2->4->3
// only second half of list is reversed  // 3->4->5   reverse 5->4->3
//  1->2->3
//  5->4-> 3

class Solution { //O(N)  O(1)
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        // find the mid 
        ListNode* curr= head;
        ListNode* mid = findMid(head);
        
        // breaking list into two half  1->2   other will be  3->4->5
        // start->mid-1   , mid -> end 
        while(curr->next != mid){
            curr= curr->next;
        }
        curr->next= NULL;
        
        // reverse the second part mid->end 
        ListNode* start= head;
        
        // mid will be the last node after reordering 
        ListNode* end= reverseList(mid);
        
        // make the connections 
        ListNode* nlist= new ListNode(0);
        ListNode* list = nlist;
        // start =1->2->NULL
        // end = 5->4->3
        while(start){
            list->next= start; // list->1    start=1
            start= start->next; // start=2
            list= list->next;
            
            list->next= end; // list->1->5
            end= end->next;
            list= list->next;
        }
        // return the new list head 
        head = nlist->next;
    }
    ListNode* reverseList(ListNode* mid){
        if(!mid) return NULL;
        ListNode* prev=NULL;
        ListNode* curr= mid;
        ListNode* nxt;
        while(curr!=NULL){
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        return prev;
    }
    
    ListNode* findMid(ListNode* curr){
        ListNode* slow= curr;
        ListNode* fast = curr;
        while(fast && fast->next){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};



// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4};
    ListNode *head=createList(a);
    sol.reorderList(head);
    printList(head);
    return 0;
}