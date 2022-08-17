/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
class Solution { //O(2n)   O(1)
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {  
        ListNode *curr=head;
        int lenght=0;
        // finding the total len 
        while(curr!=NULL){
            lenght++;
            curr = curr->next;
        }
        if(lenght == n) // remove first node
            return head->next;

        curr= head;
        for(int i=1; i<lenght-n; i++){
            curr= curr->next;
        }
        curr->next = curr->next->next;
       return head;
    }
};

// using fast and slow concept  .. fast and slow in beginning pointing at null
// move fast till n 
// then move slow and fast by one step till fast reaches end 
// when fast reaches end just remove the connections 
// slow next node will be the one that we want to delete 

class Solution { //O(n)  O(1)
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* fast = head;
        ListNode* slow= head;

        for(int i=0;i<n;i++)
            fast= fast->next;
        // if fast already reached the end 
        if(!fast) return head->next;
        // move both together till fast doesnot reach end 
        while(fast->next){
            fast= fast->next;
            slow= slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3,4,5};
    int n=2;
    ListNode *head=createList(a);
    ListNode *ans=sol.removeNthFromEnd(head,n);
    printList(ans);
    return 0;
}