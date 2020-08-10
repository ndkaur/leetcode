/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> out;
        int len =0;
        ListNode *curr= root;
        while(curr){
            curr=curr->next;
            len++;  // len =3  k=5
        }
        int part_size=len/k; // 3
        int rem= len%k; // 2

        curr=root;
        while(k--){
            ListNode *head= new ListNode(-1);
            ListNode * innercurr=head;
            if(!curr){
                out.push_back(head->next);
                continue;
            }
            int extra = rem ? 1:0;
            if(rem)  rem--;

            for(int i=0;i<part_size+extra;i++){
                innercurr->next=curr;
                innercurr=innercurr->next;
                curr=curr->next;
            }
            innercurr->next=NULL;
            out.push_back(head->next);
        }
        return out;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> a={1,2,3};
    ListNode *root=createList(a);
    int k=5;
    vector<ListNode *> out=sol.splitListToParts(root,k);
    for(auto node:out){
        printList(node); 
    }
    return 0;
}