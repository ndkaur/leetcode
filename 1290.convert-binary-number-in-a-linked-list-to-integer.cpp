/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */
#include "bits/stdc++.h"
// #include "Tree.h"
using namespace std;
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        if(!head)
            return ans;
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp= temp->next;
        }

        len = len-1;
        while(head){
            if(head->val==1){
                ans+= pow(2,len);
            }
            len--;
            head= head->next;
        }
        return ans;
    }
};



//  binary representation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head==NULL)
            return 0;
        int ans=0;
        while(head){
            ans=ans*2;
            ans=ans+head->val;
            head=head->next;
        }
        return ans;
    }
};


// bit manipulation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans =0;
        if(head==NULL)
            return 0;
        while(head){
            ans= (ans<<1) | head->val;
            head= head->next;
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution sol;
    vi a = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    ListNode* head= createList(a);
    int ans=sol.getDecimalValue(head);
    cout<<ans;
    return 0;
}