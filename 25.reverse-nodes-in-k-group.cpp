/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverse(ListNode *head){
        ListNode *curr;
        ListNode *prev;
        ListNode *temp;
        curr=head;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy =new ListNode(-1);
        ListNode *prev=dummy;
        prev->next=head;
        ListNode *curr;
        ListNode *nextnode;
        while(prev){
            curr=prev;
            for(int i=0;i<k;i++){
                if(curr){
                    curr=curr->next;
                }
            }
            if(!curr) break;
            else
                nextnode=curr->next;
            
            curr->next=NULL;
            prev->next= reverse(prev->next);

            for(int i=0;i<k;i++){
                prev=prev->next;
            }
            prev->next=nextnode;
        }
        return dummy->next;
    }
};



class Solution { //t-> O(n)  sc-> O(n/k)
public:
    void reverse(ListNode* start, ListNode* end){
        ListNode* curr= start;
        ListNode* nxt;
        ListNode* prev= NULL;
        while(prev!=end){
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1)
            return head;
        ListNode* start= head;
        ListNode* end= head;
        int ptr= k-1; // 0 based indexing 
        // dividing into k groups 
        while(ptr--){ // ptr will reach the end of each kth group 
            end= end->next;
            if(end==NULL) // no k divisions can be made from the remaining list 
                return head;
        }
        // recursiively reversing the remaining elemts 
        ListNode* nextHead = reverseKGroup(end->next, k);
        reverse(start, end);
        // after reversing the start and end will change
        // start will get at the end so attach the start to the next remaining reversed list 
        start->next= nextHead;
        // end after reversal becomes the start pointer ie the head
        return end;
    }
};

class Solution { // space O(1)  removed the recursive stack space and used the itetarive method 
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head ||!head->next || k==1)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* end = head;

        int i=0;
        while(end!=NULL){
            i++;
            if(i%k==0){ // multiple of k , reverse
                ListNode* start = prev->next;
                ListNode* nxt = end->next;
                reverse(start, end);
                prev->next= end;
                start->next = nxt;
                prev = start;
                end = nxt;
            }
            else
                end= end->next;
        }
        return dummy->next;
    }
    void reverse(ListNode* start, ListNode* end){
        ListNode* prev=NULL;
        ListNode* curr = start;
        ListNode* nxt;
        while(prev!=end){
            nxt = curr->next;
            curr->next = prev;
            prev= curr;
            curr= nxt;
        }
    }
};

class Solution {  //space->O(N)
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur= head;
        for(int i=0;i<k; i++){
            if(!cur) return head;
            cur = cur->next;
        }
        ListNode* curr= head;
        ListNode* prev=NULL;
        ListNode* nxt = NULL;
        for(int i=0;i<k; i++){
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        head->next= reverseKGroup(curr, k);
        return prev;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4,5};
    ListNode *head=createList(a);
    int k=3;
    ListNode *ans=sol.reverseKGroup(head,k);
    printList(ans);
    return 0;
}