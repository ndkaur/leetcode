/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {1
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast !=NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {// proves cyclic
                fast=head; // to find the beginning node
                while(slow!=fast){ 
                    slow=slow->next;
                    fast=fast->next;
                }
            return slow;
            }
        }
        return NULL;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> a={3,2,0,-4};
    ListNode *head=createList(a);
    ListNode *ans=sol.detectCycle(head);
    printList(ans);
    return 0;
}

